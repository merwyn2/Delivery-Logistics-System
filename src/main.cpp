#include "Product.h"
#include "OrderItem.h"

int main(){
    Product p(1, "iPhone 16", "Apple");
    OrderItem item(p, 2);
    
    return 0;
}