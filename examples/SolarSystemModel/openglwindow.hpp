#ifndef OPENGLWINDOW_HPP_
#define OPENGLWINDOW_HPP_

#include <vector>
#include "abcg.hpp"
#include "camera.hpp"
#include "model.hpp"

/*struct Vertex {
  glm::vec3 position;

  bool operator==(const Vertex& other) const {
    return position == other.position;
  }
};*/

class OpenGLWindow : public abcg::OpenGLWindow {
 protected:
  void handleEvent(SDL_Event& ev) override;
  void initializeGL() override;
  void paintGL() override;
  void paintUI() override;
  void resizeGL(int width, int height) override;
  void terminateGL() override;

 private:
  GLuint m_VAO{};
  GLuint m_VBO{};
  GLuint m_EBO{};
  GLuint m_program{};

  int m_viewportWidth{};
  int m_viewportHeight{};

  Camera m_camera;
  Model m_sun_model;
  Model m_earth_model;
  Model m_mercurio_model;
  Model m_venus_model;
  Model m_mars_model;
  Model m_jupiter_model;
  Model m_neptuno_model;
  Model m_saturn_model;
  Model m_uranus_model;
  Model m_pluto_model;

  float m_dollySpeed{0.0f};
  float m_truckSpeed{0.0f};
  float m_liftSpeed{0.0f};
  float m_panSpeed{0.0f};
  // Tentativa de fazer a camera do eixo X
  float m_panXSpeed{0.0f};

  std::vector<Vertex> m_vertices;
  std::vector<GLuint> m_indices;

  //void loadModelFromFile(std::string_view path);
  void update();
};

#endif