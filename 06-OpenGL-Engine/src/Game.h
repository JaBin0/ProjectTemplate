#pragma once
// Own headers
#include <OOPEngine.h>

class Game : public OOPEngine {
public:
    void loadScene() override;

protected:
    void init() override;
};