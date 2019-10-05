#ifndef Game_hpp
#define Game_hpp

#include <memory>
#include "./GameObject.hpp"
#include "./Map.hpp"

class Game {
public:    
    void init();
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() { return isRunning; }
    
private:
    bool isRunning;
    std::unique_ptr<GameObject> player;
    std::unique_ptr<Map> map;
};

#endif /* Game_hpp */
