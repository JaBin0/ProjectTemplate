#pragma once
// System headers
#include <glad/glad.h>

/* Brief:
 *   TODO!
*/
class OGl {
public:
    /* Brief:
     *   Constructors & Destructor
    */
    OGl();
    ~OGl();

    /* Brief:
     *   TODO!
    */
    void init(GLADloadproc procAddress);

    /* Brief:
     *   TODO!
    */
    void draw();
};