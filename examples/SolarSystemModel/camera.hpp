#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

class OpenGLWindow;

class Camera {
 public:
  void computeViewMatrix();
  void computeProjectionMatrix(int width, int height);

  void dolly(float speed);
  void lift(float speed);
  void truck(float speed);
  void pan(float speed);
  // Tentativa de fazer a camera do eixo X
  void panX(float speed);

 private:
  friend OpenGLWindow;

  glm::vec3 m_eye{glm::vec3(0.0f, 0.0f, 0.5f)};  // Camera position
  glm::vec3 m_at{glm::vec3(0.0f, 0.0f, 0.0f)};   // Look-at point
  glm::vec3 m_up{glm::vec3(0.0f, 1.0f, 0.0f)};   // "up" direction
  glm::vec3 x{glm::vec3(1.0f, 0.0f, 0.0f)};

  // Matrix to change from world space to camera soace
  glm::mat4 m_viewMatrix;

  // Matrix to change from camera space to clip space
  glm::mat4 m_projMatrix;
};

#endif