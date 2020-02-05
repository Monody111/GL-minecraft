//
//  Game.cpp
//  testSFML
//
//  Created by Chen.Zr on 2020/1/25.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "Game.hpp"

void Game::runLoop() {
    while (!glfwWindowShouldClose(window)) {
        
        GLfloat currentTime = glfwGetTime();
        GLfloat deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        
        glfwPollEvents();
        
        player -> movement(deltaTime);
        player -> view();
        player -> verticality(deltaTime);
        
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        skyboxRenderer -> renderSky();
        renderer->render(this -> texture);
        
        glfwSwapBuffers(window);
    }
    glfwTerminate();
}

Game::Game(GameSetting *setting){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    this -> setting = setting;
    loadWindow();
    glewExperimental = GL_TRUE;
    glewInit();
}

void Game::loadRenderer() {
    
    
    skyboxRenderer = new SkyboxRenderer("SkyBoxVertShader.glsl",
                                        "SkyBoxFrag.glsl");
    skyboxRenderer -> bindCamera(player -> camera);
    
    Section *s = new Section();
    
    renderer = new InstancingRenderer("instancingShader.glsl",
                                      "FragShader.glsl");
    renderer -> bindCamera(player -> camera);
    renderer -> bindModel(s -> model);
    
    texture = new BasicTexture("Test.png");
}

void Game::loadWindow() {
    
    if (setting -> fullScreen) {
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *vm = glfwGetVideoMode(monitor);
        setting -> width = vm -> width;
        setting -> height = vm -> height;
        window=glfwCreateWindow(vm -> width, vm -> height,"GL",monitor, nullptr);
    }else{
        window=glfwCreateWindow(setting->width, setting->height,"GL",nullptr, nullptr);
    }
    glfwMakeContextCurrent(window);
    
    player = new Player(this -> setting, glm::vec3(8.0, -1.0, 8.0));
    glfwSetWindowUserPointer(window, this -> player -> controller);
    
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursorpos_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    glViewport(0, 0, setting->width, setting->height);
    
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_DEPTH_TEST);
//    glCullFace(GL_BACK);
}



