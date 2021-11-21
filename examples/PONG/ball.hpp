#ifndef BALL_HPP_
#define BALL_HPP_

#include <list>

#include "Player1.hpp"
#include "Player2.hpp"
#include "abcg.hpp"
#include "gamedata.hpp"

class ball;
class OpenGLWindow;

class Ball {
 public:
  void initializeGL(GLuint program);
  void paintGL(const GameData &gameData);
  void terminateGL();

  void update(float deltaTime, int &directionX, int &directionY);
  void setTranslation(glm::vec2 translation) { m_translation = translation; }

 private:
  friend OpenGLWindow;

  GLuint m_program{};
  GLint m_translationLoc{};
  GLint m_colorLoc{};
  GLint m_scaleLoc{};

  GLuint m_vao{};
  GLuint m_vbo{};
  GLuint m_ebo{};

  glm::vec4 m_color{1};

  float m_scale{0.025f};
  glm::vec2 m_translation{glm::vec2(0)};
  glm::vec2 m_velocity{glm::vec2(0)};
  glm::vec2 m_position{glm::vec2(0)};

  abcg::ElapsedTimer m_ballMoveTimer;
};

#endif