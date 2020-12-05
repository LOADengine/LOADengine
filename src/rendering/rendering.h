#pragma once

struct Mesh
{
    int numVerts;
    void *verts;
};

void RenderMesh(Mesh* mesh);