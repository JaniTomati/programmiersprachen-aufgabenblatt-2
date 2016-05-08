// clock.cpp (Programmiersprachen Aufgabenblatt 2)

#include "window.hpp"
#include <utility>
#include <cmath>
#include <vector>
#include "rectangle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "color.hpp"

int main(int argc, char * argv[]) {
  Window win{std::make_pair(600,600)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    auto time_ = win.get_time();

    Circle base {{0.5f, 0.5f}, 0.4f, {0.4f, 0.0f, 1.0f}};
    base.draw_clock(win);
    base.draw(win);

    float angle = M_PI * 2 / 60;
    float sec = time_;
    float min = time_ / 60;
    float h = time_ / (12 * 60);

    win.draw_line(0.5f, 0.5f, 0.5f + sin(angle * sec) * 0.35f, 0.5f + cos(angle * sec) * 0.35f, 0.9f, 0.1f, 0.1f);
    win.draw_line(0.5f, 0.5f, 0.5f + sin(angle * min) * 0.3f, 0.5f + cos(angle * min) * 0.3f, 0.1f, 0.9f, 0.1f);
    win.draw_line(0.5f, 0.5f, 0.5f + sin(angle * h) * 0.2f, 0.5f + cos(angle * h) * 0.2f, 1.0f, 1.0f, 0.0f); 

    win.update();
  }

  return 0;
}