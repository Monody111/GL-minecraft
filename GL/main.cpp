//
//  main.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/10/20.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
//#include "Shader/ShaderLoader.hpp"
//#include "Camera.hpp"
//#include "Texture.hpp"
//#include "Model.hpp"
#include "DefaultRenderer.hpp"
#include "CubeComponent.hpp"
//#include "CubeRenderer.hpp"
#include "GameSetting.hpp"
#include "Game.hpp"


//void init();
//void movement();
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

//GLFWwindow * window;
//Camera *camera = nullptr;
//CubeComponent *cube = nullptr;
//Shader *shader = nullptr;
//Renderer *renderer = nullptr;
//GameSetting *setting;


//bool keys[1024];
//bool firstMouse = true;
//GLfloat deltaTime = 0.0f;
//GLfloat lastTime = 0.0f;
//GLfloat lastX = 400, lastY = 300;

int main(int argc, const char * argv[]) {

//    init();
    GameSetting *setting = new GameSetting();
    Game *game = new Game(setting);
    game -> loadRenderer();
    game -> runLoop();
//    while (!glfwWindowShouldClose(window)) {
//
//        GLfloat currentTime = glfwGetTime();
//        deltaTime = currentTime - lastTime;
//        lastTime = currentTime;
//
//        glfwPollEvents();
//        movement();
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glClearColor(0.0, 0.0f, 0.0f, 1.0);
//        renderer->render();
//        glfwSwapBuffers(window);
//    }
//    glfwTerminate();

}

//void init(){
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    window = glfwCreateWindow(WIDTH, HEIGHT, "GL", nullptr, nullptr);
//    glfwMakeContextCurrent(window);
//    glewExperimental = GL_TRUE;
//    glewInit();
//    glViewport(0, 0, WIDTH, HEIGHT);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glEnable(GL_DEPTH_TEST);
//    glfwSetKeyCallback(window, key_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    camera = new Camera(glm::vec3(0.0,0.0,10.0));
//    cube = new CubeComponent();
//    shader =
//    new Shader("/Users/chen.zr/workspace/GL/GL/GL/Shader/VertShader.glsl",
//               "/Users/chen.zr/workspace/GL/GL/GL/Shader/FragShader.glsl");
//
//    renderer = new DefaultRenderer();
//    renderer->bindCamera(camera);
//    renderer->bindMesh(cube);
//    renderer->bindShader(shader);
//}

//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//    if (key >= 0 && key <= 1024) {
//        if (action == GLFW_PRESS) {
//            keys[key] = true;
//        }else if (action == GLFW_RELEASE){
//            keys[key] = false;
//        }
//    }
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos){
//    if (firstMouse) {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//    GLfloat xoffset = xpos - lastX ;
//    GLfloat yoffset = lastY - ypos;
//
//    lastX = xpos;
//    lastY = ypos;
//    camera->ProcessMouseMovement(xoffset, yoffset);
//}
//
//void movement(){
//    if (keys[GLFW_KEY_W]) {
//        camera->ProcessKeyboard(FORWARD, deltaTime);
//    }
//    if (keys[GLFW_KEY_S]) {
//        camera->ProcessKeyboard(BACKWARD, deltaTime);
//    }
//    if (keys[GLFW_KEY_A]) {
//        camera->ProcessKeyboard(LEFT, deltaTime);
//    }
//    if (keys[GLFW_KEY_D]) {
//        camera->ProcessKeyboard(RIGHT, deltaTime);
//    }
//
//}

