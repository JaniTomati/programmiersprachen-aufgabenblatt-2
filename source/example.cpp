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

    /*Rectangle r1 {{0.25f, 0.25f}, 0.5f, 0.5f, {0.6f, 0.0f, 0.75f}};
    r1.draw(win);
    Rectangle r2 {{0.38f, 0.37f}, 0.25f, 0.25f, {0.4f, 0.0f, 1.0f}};
    r2.draw(win, {0.3f, 0.2f, 0.3f});
    Circle c1 {{0.5f, 0.5f}, 0.3f, {0.0f, 0.75f, 1.0f}};
    c1.draw(win);
    Circle c2 {{0.5f, 0.5f}, 0.2f, {1.0, 0.0, 0.84}};
    c2.draw(win, {0.3, 1.0, 0.12});*/

    std::vector<Circle> circles;
    circles.push_back({{0.5f, 0.5f}, 0.3f, {0.0f, 0.75f, 1.0f}});
    circles.push_back({{0.5f, 0.5f}, 0.2f, {1.0f, 0.0f, 0.84f}});
    circles.push_back({{0.5f, 0.5f}, 0.4f, {0.4f, 0.0f, 1.0f}});

    std::vector<Rectangle> rectangles;
    rectangles.push_back({{0.25f, 0.25f}, 0.5f, 0.5f, {0.6f, 0.0f, 0.75f}});
    rectangles.push_back({{0.38f, 0.37f}, 0.25f, 0.25f, {0.4f, 0.0f, 1.0f}});

    circles[0].draw(win);
    circles[1].draw(win);
    circles[2].draw(win, {0.3, 1.0, 0.12});

    rectangles[0].draw(win);
    rectangles[1].draw(win, {0.3f, 0.2f, 0.3f});

    auto mouse_pos = win.mouse_position();
    Vec2 mouse(mouse_pos.first, mouse_pos.second); // Position des Mauszeigers

    for (int i = 0; i <= circles.size(); ++i) {
      if (circles[i].is_inside(mouse)) {
        circles[i].draw(win, {0.0f, 0.0f, 1.0f});
      }
    }

    for (int i = 0; i <= circles.size(); ++i) {
      if (rectangles[i].is_inside(mouse)) {
        rectangles[i].draw(win, {0.0f, 0.0f, 1.0f});
      }
    }
    
    win.update();
  }

  return 0;
}

/*int main(int argc, char* argv[]) {
  Window win{std::make_pair(600,600)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    auto t = win.get_time();
    float x1{0.5f + 0.5f * std::sin(t)};
    float y1{0.5f + 0.5f * std::cos(t)};

    float x2{0.5f + 0.5f * std::sin(2.0f*t)};
    float y2{0.5f + 0.5f * std::cos(2.0f*t)};

    float x3{0.5f + 0.5f * std::sin(t-10.f)};
    float y3{0.5f + 0.5f * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);

    win.update();
  }

  return 0;
}*/
