#include "ScriptingInput.hpp"
#include "Input.hpp"
#include <algorithm>
#include <cctype>

namespace Elysium {

/**
 * @brief Converts a key name string to a KeyCode.
 * @param name Key name string.
 * @return KeyCode enum value.
 */
static KeyCode StringToKeyCode(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c) {
        return static_cast<char>(std::toupper(c));
    });

    if (name == "A") return KeyCode::A;
    if (name == "B") return KeyCode::B;
    if (name == "C") return KeyCode::C;
    if (name == "D") return KeyCode::D;
    if (name == "E") return KeyCode::E;
    if (name == "F") return KeyCode::F;
    if (name == "G") return KeyCode::G;
    if (name == "H") return KeyCode::H;
    if (name == "I") return KeyCode::I;
    if (name == "J") return KeyCode::J;
    if (name == "K") return KeyCode::K;
    if (name == "L") return KeyCode::L;
    if (name == "M") return KeyCode::M;
    if (name == "N") return KeyCode::N;
    if (name == "O") return KeyCode::O;
    if (name == "P") return KeyCode::P;
    if (name == "Q") return KeyCode::Q;
    if (name == "R") return KeyCode::R;
    if (name == "S") return KeyCode::S;
    if (name == "T") return KeyCode::T;
    if (name == "U") return KeyCode::U;
    if (name == "V") return KeyCode::V;
    if (name == "W") return KeyCode::W;
    if (name == "X") return KeyCode::X;
    if (name == "Y") return KeyCode::Y;
    if (name == "Z") return KeyCode::Z;

    if (name == "SPACE") return KeyCode::Space;
    if (name == "ENTER" || name == "RETURN") return KeyCode::Enter;
    if (name == "ESCAPE" || name == "ESC") return KeyCode::Escape;
    if (name == "LSHIFT" || name == "SHIFT") return KeyCode::LShift;
    if (name == "RSHIFT") return KeyCode::RShift;
    if (name == "LCTRL" || name == "CTRL") return KeyCode::LControl;
    if (name == "RCTRL") return KeyCode::RControl;
    if (name == "TAB") return KeyCode::Tab;
    if (name == "BACKSPACE") return KeyCode::Backspace;

    if (name == "LEFT") return KeyCode::Left;
    if (name == "RIGHT") return KeyCode::Right;
    if (name == "UP") return KeyCode::Up;
    if (name == "DOWN") return KeyCode::Down;

    if (name == "0") return KeyCode::Num0;
    if (name == "1") return KeyCode::Num1;
    if (name == "2") return KeyCode::Num2;
    if (name == "3") return KeyCode::Num3;
    if (name == "4") return KeyCode::Num4;
    if (name == "5") return KeyCode::Num5;
    if (name == "6") return KeyCode::Num6;
    if (name == "7") return KeyCode::Num7;
    if (name == "8") return KeyCode::Num8;
    if (name == "9") return KeyCode::Num9;

    return KeyCode::Unknown;
}

/**
 * @brief Checks if a key is held down.
 * @param key Key code.
 * @return true if held down, false otherwise.
 */
bool IsKeyDown(KeyCode key) {
    return Input::IsKeyDown(key);
}

/**
 * @brief Checks if a key is held down.
 * @param keyName Key name string.
 * @return true if held down, false otherwise.
 */
bool IsKeyDown(const std::string& keyName) {
    return IsKeyDown(StringToKeyCode(keyName));
}

/**
 * @brief Checks if a key was pressed this frame.
 * @param key Key code.
 * @return true if pressed this frame, false otherwise.
 */
bool IsKeyPressed(KeyCode key) {
    return Input::IsKeyPressed(key);
}

/**
 * @brief Checks if a key was pressed this frame.
 * @param keyName Key name string.
 * @return true if pressed this frame, false otherwise.
 */
bool IsKeyPressed(const std::string& keyName) {
    return IsKeyPressed(StringToKeyCode(keyName));
}

/**
 * @brief Checks if a key was released this frame.
 * @param key Key code.
 * @return true if released this frame, false otherwise.
 */
bool IsKeyReleased(KeyCode key) {
    return Input::IsKeyReleased(key);
}

/**
 * @brief Checks if a key was released this frame.
 * @param keyName Key name string.
 * @return true if released this frame, false otherwise.
 */
bool IsKeyReleased(const std::string& keyName) {
    return IsKeyReleased(StringToKeyCode(keyName));
}

/**
 * @brief Checks if a mouse button is held down.
 * @param button Mouse button code.
 * @return true if held down, false otherwise.
 */
bool IsMouseDown(MouseCode button) {
    return Input::IsMouseButtonDown(button);
}

/**
 * @brief Checks if a mouse button was clicked this frame.
 * @param button Mouse button code.
 * @return true if clicked this frame, false otherwise.
 */
bool IsMouseClicked(MouseCode button) {
    return Input::IsMouseButtonPressed(button);
}

/**
 * @brief Gets the mouse position in world coordinates.
 * @return Mouse position as Vector2.
 */
Vector2 GetMousePosition() {
    sf::Vector2f rawPos = Input::GetMousePosition();
    constexpr float PIXELS_PER_METER = 50.0f;
    return {rawPos.x / PIXELS_PER_METER, rawPos.y / PIXELS_PER_METER};
}

} // namespace Elysium
