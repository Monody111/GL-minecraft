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
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0, 0.0f, 0.0f, 1.0);
        renderer->render();
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
    Shader *shader =
    new Shader ("/Users/chen.zr/workspace/GL/LearnOpenGL/LearnOpenGL/Shader/VertShader.glsl",
               "/Users/chen.zr/workspace/GL/LearnOpenGL/LearnOpenGL/Shader/FragShader.glsl");
    
    Camera *camera = new Camera(glm::vec3(0.0, 0.0, 3.0), this -> setting);
    
    CubeComponent *mesh = new CubeComponent();
    
    renderer = new DefaultRenderer();
    renderer -> bindShader(shader);
    renderer -> bindCamera(camera);
    renderer -> bindMesh(mesh);
}

void Game::loadWindow() {
    
    if (setting -> fullScreen) {
        const GLFWvidmode *vm = glfwGetVideoMode(glfwGetPrimaryMonitor());
        setting -> width = vm -> width;
        setting -> height = vm -> height;
    }
    c = new Controller();
    window=glfwCreateWindow(setting->width, setting->height,"GL",nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this -> c);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursorpos_callback);
    glViewport(0, 0, setting->width, setting->height);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_DEPTH_TEST);
}

void processKey(int key, int scancode, int action, int mods){
    std::cout << key << " "<< scancode << " " << action << " " << mods << std::endl;
}



