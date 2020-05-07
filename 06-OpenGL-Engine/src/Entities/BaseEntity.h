#pragma once

#include <OGl.h>

/* Brief:
 *   TODO!
*/
class BaseEntity {
public:
    virtual void update() = 0;

    virtual void draw(OGl* const renderer) = 0;
};