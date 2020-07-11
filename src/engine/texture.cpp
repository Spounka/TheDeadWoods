//
// Created by spounka on 13/06/2020.
//

#include "engine/graphics/texture.hpp"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"


namespace SE::Graphics
{
	Texture::Texture(const char* texturePath)
	{
		int width, height, nChannels;
		unsigned char* data = stbi_load(texturePath,&width, &height, &nChannels, 0);
		if(data)
		{
			glGenTextures(1, &m_texture);
			glBindTexture(GL_TEXTURE_2D, m_texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			
		}
		else
			std::cerr << "failed to load texture\n";
		stbi_image_free(data);
		Bind();
	}
	
	void Texture::Bind() 
	{
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}
}
