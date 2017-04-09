// defines the primitive shapes
#ifndef SHAPES_H
#define SHAPES_H

class shapes
{
        int x,y;    // mid point coordinates
    public:
        // contructors and destructors
        shapes();
        ~shapes() = default;
        shapes(const shapes& other) = default;
        shapes(shapes&& other) = default;
        shapes& operator=(const shapes& other) = default;
        shapes& operator=(shapes&& other) = default;

        // custom function
        int triange(int *vertices);
};

#endif
