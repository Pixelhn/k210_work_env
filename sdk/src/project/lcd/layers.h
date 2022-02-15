//图层队列

struct layer
{
    int layer_num;

    struct layer *next_layer;
};
typedef struct layer layer_s;


int add_node(layer_s a_layer, int layer_num);
int out_node();
/***

int creat_layer();
int delete_layer();
struct chec(layer_num);***/

