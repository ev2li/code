#include "JObject.h"
using namespace json;

void* JObject::value(){
    switch(m_type){
        case T_NULL:
            return get_if<str_t>(&m_value);
        case T_BOOL:
            return get_if<bool_t>(&m_value);
        case T_INT:
            return get_if<int_t>(&m_value);
        case T_DOUBLE:
            return get_if<double_t>(&m_value);
        case T_LIST:
            return get_if<list_t>(&m_value);
        case T_DICT:
            return get_if<dict_t>(&m_value);
        case T_STR:
            return std::get_if<str_t>(&m_value);
        default:
            return nullptr;
    }
}


JObject::JObject(){

}
