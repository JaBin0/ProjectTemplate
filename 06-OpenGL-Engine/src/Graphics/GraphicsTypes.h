#pragma once
// System headers
#include <vector>

/* Brief:
 *  Store information about loaded mesh.
*/
typedef struct VAO {
    /* Brief:
     *  Id of vertex array object loaded to the graphic.
    */
    uint32_t vaoId = -1;

    /* Brief:
     *  Id of vertex buffer object attached to the vao.
    */
    uint32_t vboId = -1;

    /* Brief:
     *  Number of vertieces in the mesh to load.
    */
    uint32_t size = 0;
}; 

/* Brief:
 *  Store description of the mesh.
*/
typedef struct MeshDiscription {
    /* Brief:
     *   Size of the buffer if vertices is not empty .
    */
    uint32_t bufferSize = 0;

    /* Brief:
     *  Vertices which should be loaded to the graphics.
    */
    std::vector<float> vertices = {};

    /* Brief:
     *  offsets of each vertex part.
    */
    std::vector<uint32_t> offsets = {};
};