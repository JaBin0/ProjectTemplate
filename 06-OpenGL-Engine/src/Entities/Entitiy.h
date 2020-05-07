#pragma once
// Engine headers
#include <BaseEntity.h>

class Entitiy : public BaseEntity {
public:
    void update() override;

    void draw(OGl* const renderer) override;
};