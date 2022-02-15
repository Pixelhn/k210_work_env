#include <stddef.h>

#include "layers.h"

//全局变量
layer_s basic_layer = {
    .layer_num = 0,
    .next_layer = NULL
};
int total_layers = 1;

layer_s * get_head_node()
{
    return &basic_layer;
}

//添加删除结点
int add_node(layer_s a_layer, int layer_num)
{
    layer_s *player = get_head_node;
}

//操作队列