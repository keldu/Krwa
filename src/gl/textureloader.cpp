#include "textureloader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>
#include <iostream>



GLuint loadPNG(const char *png_file_path){

        png_structp png_ptr;
        png_infop info_ptr;
        unsigned int sig_read = 0;
        int color_type, interlace_type;
        FILE *fp;

        if ((fp = fopen(png_file_path, "rb")) == NULL)
            return false;
        png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
                                         NULL, NULL, NULL);

        if (png_ptr == NULL) {
            fclose(fp);
            return false;
        }

        /* Allocate/initialize the memory
         * for image information.  REQUIRED. */
        info_ptr = png_create_info_struct(png_ptr);
        if (info_ptr == NULL) {
            fclose(fp);
            png_destroy_read_struct(&png_ptr, NULL, NULL);
            return false;
        }

        if (setjmp(png_jmpbuf(png_ptr))) {
            /* Free all of the memory associated
             * with the png_ptr and info_ptr */
            png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
            fclose(fp);
            /* If we get here, we had a
             * problem reading the file */
            return false;
        }

        /* Set up the output control if
         * you are using standard C streams */
        png_init_io(png_ptr, fp);

        /* If we have already
         * read some of the signature */
        png_set_sig_bytes(png_ptr, sig_read);

        png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);

        png_uint_32 width, height;
        int bit_depth;
        png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type,
                     &interlace_type, NULL, NULL);

        unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
        GLubyte *data;
        data = (unsigned char*) malloc(row_bytes * height);

        png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);

        for (int i = 0; i < height; i++) {
            // note that png is ordered top to
            // bottom, but OpenGL expect it bottom to top
            // so the order or swapped
            memcpy(data+(row_bytes * (height-1-i)), row_pointers[i], row_bytes);
        }

        /* Clean up after the read,
         * and free any memory allocated */
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

        /* Close the file */
        fclose(fp);
    std::cerr<<width<<" "<<height<<std::endl;

    GLuint textureID;

    glGenTextures(1, &textureID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0 ,GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    // OpenGL has now copied the data. Free our own version

    // Poor filtering, or ...
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // ... nice trilinear filtering.

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
    glBindTexture(GL_TEXTURE_2D, 0);
    // Return the ID of the texture we just created
    return textureID;

}

GLuint loadBMP(const char * imagepath){

    printf("Reading image %s\n", imagepath);

    // Data read from the header of the BMP file
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int imageSize;
    unsigned int width, height;
    // Actual RGB data
    unsigned char * data;

    // Open the file
    FILE * file = fopen(imagepath,"rb");
    if (!file)							    {printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", imagepath); getchar(); return 0;}

    // Read the header, i.e. the 54 first bytes

    // If less than 54 bytes are read, problem
    if ( fread(header, 1, 54, file)!=54 ){
        printf("Not a correct BMP file\n");
        return 0;
    }
    // A BMP files always begins with "BM"
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file\n");
        return 0;
    }
    // Make sure this is a 24bpp file
    if ( *(int*)&(header[0x1E])!=0  )         {printf("Not a correct BMP file\n");    return 0;}
    if ( *(int*)&(header[0x1C])!=24 )         {printf("Not a correct BMP file\n");    return 0;}

    // Read the information about the image
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    // Some BMP files are misformatted, guess missing information
    if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos==0)      dataPos=54; // The BMP header is done that way

    //  printf("%u \n",dataPos);
    //dataPos += 10000;
    // Create a buffer
    data = new unsigned char [imageSize];

    fseek(file, dataPos-54, 1);
    //fseek(file, 1, dataPos -54);

    // Read the actual data from the file into the buffer
    fread(data,1,imageSize,file);

    // Everything is in memory now, the file wan be closed
    fclose (file);

    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    // OpenGL has now copied the data. Free our own version
    delete [] data;

    // Poor filtering, or ...
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // ... nice trilinear filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Return the ID of the texture we just created
    return textureID;
}

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

GLuint loadDDS(const char * imagepath){

    unsigned char header[124];

    FILE *fp;

    /* try to open the file */
    fp = fopen(imagepath, "rb");
    if (fp == NULL){
        printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", imagepath); getchar();
        return 0;
    }

    /* verify the type of file */
    char filecode[4];
    fread(filecode, 1, 4, fp);
    if (strncmp(filecode, "DDS ", 4) != 0) {
        fclose(fp);
        return 0;
    }

    /* get the surface desc */
    fread(&header, 124, 1, fp);

    unsigned int height      = *(unsigned int*)&(header[8 ]);
    unsigned int width	     = *(unsigned int*)&(header[12]);
    unsigned int linearSize	 = *(unsigned int*)&(header[16]);
    unsigned int mipMapCount = *(unsigned int*)&(header[24]);
    unsigned int fourCC      = *(unsigned int*)&(header[80]);


    unsigned char * buffer;
    unsigned int bufsize;
    /* how big is it going to be including all mipmaps? */
    bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
    buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char));
    fread(buffer, 1, bufsize, fp);
    /* close the file pointer */
    fclose(fp);

    unsigned int components  = (fourCC == FOURCC_DXT1) ? 3 : 4;
    unsigned int format;
    switch(fourCC)
    {
    case FOURCC_DXT1:
        format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        break;
    case FOURCC_DXT3:
        format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        break;
    case FOURCC_DXT5:
        format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        break;
    default:
        free(buffer);
        return 0;
    }

    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);

    unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
    unsigned int offset = 0;

    /* load the mipmaps */
    for (unsigned int level = 0; level < mipMapCount && (width || height); ++level)
    {
        unsigned int size = ((width+3)/4)*((height+3)/4)*blockSize;
        glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,
            0, size, buffer + offset);

        offset += size;
        width  /= 2;
        height /= 2;

        // Deal with Non-Power-Of-Two textures. This code is not included in the webpage to reduce clutter.
        if(width < 1) width = 1;
        if(height < 1) height = 1;

    }

    free(buffer);

    return textureID;


}

GLuint loadDATA(const char *imagepath){

    return 0;
}
