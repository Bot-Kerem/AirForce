//
// Created by kereem on 8/27/22.
//

#include "Renderer/Framebuffer.h"
#include <glad/glad.h>

#include <stdexcept>

AirForce::Framebuffer::Framebuffer(int width, int height) {
    glGenFramebuffers(1, &m_Framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);

    glGenTextures(1, &m_TextureColorbuffer);
    glBindTexture(GL_TEXTURE_2D, m_TextureColorbuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_TextureColorbuffer, 0);

    glGenRenderbuffers(1, &m_Renderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_Renderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_Renderbuffer);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        throw std::runtime_error("ERROR::FRAMEBUFFER:: Framebuffer is not complete!");
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

unsigned int AirForce::Framebuffer::getRenderImage() {
    return m_TextureColorbuffer;
}

void AirForce::Framebuffer::start() const {
    glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
}

void AirForce::Framebuffer::end() const {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

AirForce::Framebuffer::~Framebuffer() {
    glDeleteFramebuffers(1, &m_Framebuffer);
    glDeleteRenderbuffers(1, &m_Renderbuffer);
    glDeleteTextures(1, &m_TextureColorbuffer);
}
