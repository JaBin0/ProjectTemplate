#pragma once

/* Brief:
 *   TODO!
*/
class OOPEngine {
public:
    /* Brief:
     *   TODO!
    */
    OOPEngine();
    virtual ~OOPEngine();

    /* Brief:
     *   Define your scene here
    */
    virtual void loadScene() = 0;

    /* Brief:
     *   TODO!
    */
    virtual void run();
};