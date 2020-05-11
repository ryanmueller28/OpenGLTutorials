#include <stdio.h>
#include <cstdlib>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    //init glfw
    if(!glfwInit())
    {
        printf("GLFW Init failed.");
        glfwTerminate();
        return 1;
    }

    // Set up GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // <--- won't use deprecated features
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);

    if(!mainWindow)
    {
        printf("GLFW window creation failed.");
        glfwTerminate();
        return 1;
    }

    // Get Buffer size informaiton
    // Buffer is what holds openGL data as it's in window
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // set context for GLEW to use

    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        printf("GLEW initialization failed.\n");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // loop until window closed
    while (!glfwWindowShouldClose(mainWindow))
    {
        // Get + handle user input events
        glfwPollEvents();

        // clear window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }


    return EXIT_SUCCESS;
} 
