#ifndef OPENGLWINDOW_HPP_
#define OPENGLWINDOW_HPP_

#include <imgui.h>

#include <random>

#include "Player1.hpp"
#include "Player2.hpp"
#include "abcg.hpp"
#include "ball.hpp"

class OpenGLWindow : public abcg::OpenGLWindow {
 protected:
  void handleEvent(SDL_Event& event) override;
  void initializeGL() override;
  void paintGL() override;
  void paintUI() override;
  void resizeGL(int width, int height) override;
  void terminateGL() override;

 private:
  GLuint m_objectsProgram{};

  int m_viewportWidth{};
  int m_viewportHeight{};

  GameData m_gameData;

  Player1 m_player1;
  Player2 m_player2;
  Ball m_ball;

  bool isPlayer1 = true;  // If player 1 is an AI or not
  bool isPlayer2 = true;  // If player 2 is an AI or not
  int directionX = 1;     //-1 left 1 right
  int directionY = 0;     //-1 down 1 up
  int player1Score = 0;   // score Player 1
  int player2Score = 0;   // score Player 2

  abcg::ElapsedTimer m_restartWaitTimer;

  ImFont* m_font{};

  std::default_random_engine m_randomEngine;

  void restart();
  void initiate();
  void update();
  void checkCollisions();
  void checkWinCondition();
};

#endif