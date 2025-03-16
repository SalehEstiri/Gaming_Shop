#include <iostream>
#include <string>
#include <vector>

struct Product {
    std::string name{};
    int price{};
    int inventory{};
};

struct Game : public Product {};
struct Console : public Product {};
struct Monitor : public Product {};
struct Headset : public Product {};
struct Cart : public Product {};

std::vector<Game> games;
std::vector<Console> consoles;
std::vector<Monitor> monitors;
std::vector<Headset> headsets;
std::vector<Cart> cart;

int admin_wallet = 0;
int customer_wallet = 0;

void add_product(){
    std::string product_type{};
    std::cout << "What is your product type? \n";
    std::cin >> product_type;
    if (product_type == "game") {
        int size{};
        std::cout << "How many game do you want to add: \n";
        std::cin >> size;
        games.resize(size);
        for (int i = 0; i < games.size(); i++) {
            std::cout << "Enter the name of your game: \n";
            std::cin.ignore();
            std::getline (std::cin, games[i].name);
            std::cout << "Enter the price of your game: \n";
            std::cin >> games[i].price;
            std::cout << "Enter the inventory of your game: \n";
            std::cin >> games[i].inventory;
        }
    } else if (product_type == "console") {
        int size{};
        std::cout << "How many console do you want to add: \n";
        std::cin >> size;
        consoles.resize(size);
        for (int i = 0; i < consoles.size(); i++) {
            std::cout << "Enter the name of your console: \n";
            std::cin.ignore();
            std::getline (std::cin, consoles[i].name);
            std::cout << "Enter the price of your console: \n";
            std::cin >> consoles[i].price;
            std::cout << "Enter the inventory of your console: \n";
            std::cin >> consoles[i].inventory;
        }
    } else if (product_type == "monitor") {
       int size{};
        std::cout << "How many monitor do you want to add: \n";
        std::cin >> size;
        monitors.resize(size);
        for (int i = 0; i < monitors.size(); i++) {
            std::cout << "Enter the name of your monitor: \n";
            std::cin.ignore();
            std::getline (std::cin, monitors[i].name);
            std::cout << "Enter the price of your monitor: \n";
            std::cin >> monitors[i].price;
            std::cout << "Enter the inventory of your monitor: \n";
            std::cin >> monitors[i].inventory; 
        }
    } else if (product_type == "headset") {
        int size{};
        std::cout << "How many headset do you want to add: \n";
        std::cin >> size;
        headsets.resize(size);
        for (int i = 0; i < headsets.size(); i++) {
            std::cout << "Enter the name of your headset: \n";
            std::cin.ignore();
            std::getline (std::cin, headsets[i].name);
            std::cout << "Enter the price of your headset: \n";
            std::cin >>headsets [i].price;
            std::cout << "Enter the inventory of your headset: \n";
            std::cin >>headsets[i].inventory;
        }
    } else {
        std::cout << "Invalid input! \n";
    }
}

void delete_product() {
    std::string product_type{};
    std::cout << "What is your product type? \n";
    std::cin >> product_type;
    if (product_type == "game"){
        for(int i = 0; i < games.size(); i++){
            std::cout << i + 1 << "- " << games[i].name << "\n";
        }
        int choice{};
        std::cout << "Enter your choice :";
        std::cin >> choice;
        games.erase(games.begin()+ choice - 1);
    } 
    else if (product_type == "console"){
        for(int i = 0; i < consoles.size(); i++){
            std::cout << i + 1 << "- " << consoles[i].name << "\n";
        }
        int choice{};
        std::cout << "Enter your choice :";
        std::cin >> choice;
        consoles.erase(consoles.begin()+ choice - 1);
    }
    else if (product_type == "headset"){
        for(int i = 0; i < headsets.size(); i++){
            std::cout << i + 1 << "- " << headsets[i].name << "\n";
        }
        int choice{};
        std::cout << "Enter your choice :";
        std::cin >> choice;
        headsets.erase(headsets.begin()+ choice - 1);
    }
    else if (product_type == "monitor"){
        for(int i = 0; i < monitors.size(); i++){
            std::cout << i + 1 << "- " << monitors[i].name << "\n";
        }
        int choice{};
        std::cout << "Enter your choice :";
        std::cin >> choice;
        monitors.erase(monitors.begin()+ choice - 1);
    }
}

bool linear_search(std::string name, std::string product_type) {
    if (product_type == "game"){
        for(int i = 0; i < games.size(); i++){
            if(games[i].name == name){
                return true;
            } 
        } 
        return false;
    } else if (product_type == "console") {
        for(int i = 0; i < consoles.size(); i++){
            if(consoles[i].name == name){
                return true;
            } 
        } 
        return false;
    } else if (product_type == "headset") {
        for(int i = 0; i < headsets.size(); i++){
            if(headsets[i].name == name){
                return true;
            } 
        } 
        return false;
    } else if (product_type == "monitor") {
        for(int i = 0; i < monitors.size(); i++){
            if(monitors[i].name == name){
                return true;
            } 
        } 
    } 
    return false;
}

int number_search(std::string name, std::string product_type){
    if (product_type == "game"){
        for(int i = 0; i < games.size(); i++){
            if(games[i].name == name){
                return i;
            } 
        } 
    } else if (product_type == "console") {
        for(int i = 0; i < consoles.size(); i++){
            if(consoles[i].name == name){
                return i;
            } 
        } 
    } else if (product_type == "headset") {
        for(int i = 0; i < headsets.size(); i++){
            if(headsets[i].name == name){
                return i;
            } 
        } 
    } else if (product_type == "monitor") {
        for(int i = 0; i < monitors.size(); i++){
            if(monitors[i].name == name){
                return i;
            } 
        } 
    }
    return -1;
}

void search_product(){
    std::string product_type {};
    std::cout << "What's your product type ? (game/ console/ headset/ monitor) \n";
    std::cin >> product_type;
    std::string name {};
    std::cout << "What's the name of your " << product_type << " : \n";
    std::cin.ignore();
    std::getline(std::cin, name);
    if (product_type == "game"){

        if (linear_search(name, product_type)){
            std::cout << "Founded ! \n" << "it's your number " << number_search(name, product_type) + 1 << " " << product_type  << "\n";
        } else {
            std::cout << "Not founded ! \n";
        }
    } else if (product_type == "console"){

         if (linear_search(name, product_type)){
            std::cout << "Founded ! \n" << "it's your number " << number_search(name, product_type) + 1 << " " << product_type  << "\n";
        } else {
            std::cout << "Not founded ! \n";
        }
    } else if (product_type == "headset"){

         if (linear_search(name, product_type)){
            std::cout << "Founded ! \n" << "it's your number " << number_search(name, product_type) + 1 << " " << product_type  << "\n";
        } else {
            std::cout << "Not founded ! \n";
        }
    } else if (product_type == "monitor"){
        
         if (linear_search(name, product_type)){
            std::cout << "Founded ! \n" << "it's your number " << number_search(name, product_type) + 1 << " " << product_type  << "\n";
        } else {
            std::cout << "Not founded ! \n";
        }
    } 
}

void show_product(){
    if (!games.empty()){
        std::cout << "Your games are : \n";
        for(int i = 0; i < games.size(); i++){
            std::cout << i + 1 << "- " << games[i].name << std::endl;
            std::cout << "Price : " << games[i].price << std::endl;
            std::cout << "Inventory : " << games[i].inventory << std::endl;
            std::cout << "------------------------ \n";
        }
    }

    if (!headsets.empty()){
        std::cout << "Your headsets are : \n";
        for(int i = 0; i < headsets.size(); i++){
            std::cout << i + 1 << "- " << headsets[i].name << std::endl;
            std::cout << "Price : " << headsets[i].price << std::endl;
            std::cout << "Inventory : " << headsets[i].inventory << std::endl;
            std::cout << "------------------------ \n";
        }
    }

    if (!monitors.empty()){
        std::cout << "Your monitors are : \n";
        for(int i = 0; i < monitors.size(); i++){
            std::cout << i + 1 << "- " << monitors[i].name << std::endl;
            std::cout << "Price : " << monitors[i].price << std::endl;
            std::cout << "Inventory : " << monitors[i].inventory << std::endl;
            std::cout << "------------------------ \n";
        }
    }

    if (!consoles.empty()){
        std::cout << "Your consoles are : \n";
        for(int i = 0; i < consoles.size(); i++){
            std::cout << i + 1 << "- " << consoles[i].name << std::endl;
            std::cout << "Price : " << consoles[i].price << std::endl;
            std::cout << "Inventory : " << consoles[i].inventory << std::endl;
            std::cout << "------------------------ \n";
        }
    }
}

void total_value(){
    int game_p = 0;
    int headset_p = 0;
    int console_p = 0;
    int monitor_p = 0;
    int total = 0;
    for(int i = 0; i < games.size(); i++){
        game_p += games[i].price;
    }
    std::cout << "Total price of your games : " << game_p << std::endl;

    for(int i = 0; i < headsets.size(); i++){
        headset_p += headsets[i].price;
    }
    std::cout << "Total price of your headsets : " << headset_p << std::endl;

    for(int i = 0; i < consoles.size(); i++){
        console_p += consoles[i].price;
    }
    std::cout << "Total price of your consoles : " << console_p << std::endl;

    for(int i = 0; i < monitors.size(); i++){
        monitor_p += monitors[i].price;
    }
    std::cout << "Total price of your monitors : " << monitor_p << std::endl;
    
    total = game_p + headset_p + console_p + monitor_p;
    std::cout << "Total price of your product is : " << total << std::endl;
}

int admin_recharge(){
    int money {};
    std::cout << "How much money do you want to charge : \n";
    std::cin >> money;
    admin_wallet += money;
    return admin_wallet;
}

void balance(int wallet){
    std::cout << "Your wallet balance is : " << wallet << std::endl;
}

void inventory(){
    int game_i = 0;
    int console_i = 0;
    int headest_i = 0;
    int monitor_i = 0;

    if (!games.empty()){
    for(int i = 0; i < games.size(); i++){
        game_i += games[i].inventory;
    }
    std::cout << "your game invetory is : " << game_i << std::endl;
    }

    if (!consoles.empty()){
    for(int i = 0; i < consoles.size(); i++){
        console_i += consoles[i].inventory;
    }
    std::cout << "your console invetory is : " << console_i << std::endl;
    }

    if(!headsets.empty()){
    for(int i = 0; i < headsets.size(); i++){
        headest_i += headsets[i].inventory;
    }
    std::cout << "your headset invetory is : " << headest_i << std::endl;
    }

    if(!monitors.empty()){
    for(int i = 0; i < monitors.size(); i++){
        monitor_i += monitors[i].inventory;
    }
    std::cout << "your monitor invetory is : " << monitor_i << std::endl;
    }
}

void admin_menu() {
    while (true){
        std::cout << "Admin Menu: \n"
                  << "1- Add Product \n"
                  << "2- Delete Product \n"
                  << "3- Search Product \n"
                  << "4- Show All Products \n"
                  << "5- Total Price of Products \n"
                  << "6- Store wallet recharge \n"
                  << "7- Store Wallet Balance \n"
                  << "8- Show All products inventory \n"
                  << "9- Exit \n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
            add_product();
            break;
        case 2:
            delete_product();
            break;
        case 3:
            search_product();
            break;
        case 4:
            show_product();
            break;
        case 5:
            total_value();
            break;
        case 6:
            admin_recharge();
            break;
        case 7:
            balance(admin_wallet);
            break;
        case 8:
            inventory();
            break;
        case 9:
            return;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
}

int customer_recharge(){
    int money {};
    std::cout << "How much money do you want to charge : \n";
    std::cin >> money;
    customer_wallet += money;
    return customer_wallet;
}

void shop(){
    std::string product_type{};
    std::cout << "What is your product type? \n";
    std::cin >> product_type;
    Cart cart_item;

    if (product_type == "game"){
        std::cout << "-------------------------\n";
        for(int i = 0; i < games.size(); i++){
            std::cout << i + 1 << "- " << games[i].name << "\n";
        }
        std::cout << "-------------------------\n";
        int choice{}, number {};
        std::cout << "Enter your choice : \n";
        std::cin >> choice;
        if (choice > games.size ()){
            std::cout << "Invalid input ! \n";
            return;
        }
        std::cout << "How many do you want : \n";
        std::cin >> number;
        if(number > games[choice -1].inventory){
            std::cout << "Invalid input ! \n";
            return;
        }
        else if (number * (games[choice - 1].price / games[choice - 1].inventory) > customer_wallet){
            std::cout << "You don't have enough money ! \n";
            return;
        }
        cart_item.name = games[choice - 1].name;
        cart_item.price = number * (games[choice - 1].price / games[choice - 1].inventory);
        cart_item.inventory = number;
        cart.push_back(cart_item);

        std::string answer{};
        std::cout << "Are you sure about your item ? (yes / no) \n";
        std::cin >> answer;
        if (answer == "yes"){
            if (number == games[choice - 1].inventory) {
                games.erase(games.begin() + choice - 1);
            } else {
                games[choice - 1].inventory -= number;
                games[choice - 1].price -= cart_item.price;
            }
            admin_wallet += cart_item.price;
            customer_wallet -= cart_item.price;
        } 
        else if (answer == "no"){
            cart.erase(cart.end());
        } 
        else {
            std::cout << "Invalid input ! \n";
            cart.erase(cart.end());
        }
    } 

    else if (product_type == "console"){
        std::cout << "-------------------------\n";
        for(int i = 0; i < consoles.size(); i++){
            std::cout << i + 1 << "- " << consoles[i].name << "\n";
        }
        std::cout << "-------------------------\n";
        int choice{}, number {};
        std::cout << "Enter your choice : \n";
        std::cin >> choice;
        if (choice > consoles.size ()){
            std::cout << "Invalid input ! \n";
            return;
        }
        std::cout << "How many do you want : \n";
        std::cin >> number;
        if(number > consoles[choice -1].inventory){
            std::cout << "Invalid input ! \n";
            return;
        }
        else if (number * (consoles[choice - 1].price / consoles[choice - 1].inventory) > customer_wallet){
            std::cout << "You don't have enough money ! \n";
            return;
        }
        cart_item.name = consoles[choice - 1].name;
        cart_item.price = number * (consoles[choice - 1].price / consoles[choice - 1].inventory);
        cart_item.inventory = number;
        cart.push_back(cart_item);

        std::string answer{};
        std::cout << "Are you sure about your item ? (yes / no) \n";
        std::cin >> answer;
        if (answer == "yes"){
            if (number == consoles[choice - 1].inventory) {
                consoles.erase(consoles.begin() + choice - 1);
            } else {
                consoles[choice - 1].inventory -= number;
                consoles[choice - 1].price -= cart_item.price;
            }
            admin_wallet += cart_item.price;
            customer_wallet -= cart_item.price;
        } 
        else if (answer == "no"){
            cart.erase(cart.end());
        } 
        else {
            std::cout << "Invalid input ! \n";
            cart.erase(cart.end());
        }
    }

    else if (product_type == "headset"){
        std::cout << "-------------------------\n";
        for(int i = 0; i < headsets.size(); i++){
            std::cout << i + 1 << "- " << headsets[i].name << "\n";
        }
        std::cout << "-------------------------\n";
        int choice{}, number {};
        std::cout << "Enter your choice : \n";
        std::cin >> choice;
        if (choice > headsets.size ()){
            std::cout << "Invalid input ! \n";
            return;
        }
        std::cout << "How many do you want : \n";
        std::cin >> number;
        if(number > headsets[choice -1].inventory){
            std::cout << "Invalid input ! \n";
            return;
        }
        else if (number * (headsets[choice - 1].price / headsets[choice - 1].inventory) > customer_wallet){
            std::cout << "You don't have enough money ! \n";
            return;
        }
        cart_item.name = headsets[choice - 1].name;
        cart_item.price = number * (headsets[choice - 1].price / headsets[choice - 1].inventory);
        cart_item.inventory = number;
        cart.push_back(cart_item);

        std::string answer{};
        std::cout << "Are you sure about your item ? (yes / no) \n";
        std::cin >> answer;
        if (answer == "yes"){
            if (number == headsets[choice - 1].inventory) {
                headsets.erase(headsets.begin() + choice - 1);
            } else {
                headsets[choice - 1].inventory -= number;
                headsets[choice - 1].price -= cart_item.price;
            }
            admin_wallet += cart_item.price;
            customer_wallet -= cart_item.price;
        } 
        else if (answer == "no"){
            cart.erase(cart.end());
        } 
        else {
            std::cout << "Invalid input ! \n";
            cart.erase(cart.end());
        }
    }

    else if (product_type == "monitor"){
        std::cout << "-------------------------\n";
        for(int i = 0; i < monitors.size(); i++){
            std::cout << i + 1 << "- " << monitors[i].name << "\n";
        }
        std::cout << "-------------------------\n";
        int choice{}, number {};
        std::cout << "Enter your choice : \n";
        std::cin >> choice;
        if (choice > monitors.size ()){
            std::cout << "Invalid input ! \n";
            return;
        }
        std::cout << "How many do you want : \n";
        std::cin >> number;
        if(number > monitors[choice -1].inventory){
            std::cout << "Invalid input ! \n";
            return;
        }
        else if (number * (monitors[choice - 1].price / monitors[choice - 1].inventory) > customer_wallet){
            std::cout << "You don't have enough money ! \n";
            return;
        }
        cart_item.name = monitors[choice - 1].name;
        cart_item.price = number * (monitors[choice - 1].price / monitors[choice - 1].inventory);
        cart_item.inventory = number;
        cart.push_back(cart_item);

        std::string answer{};
        std::cout << "Are you sure about your item ? (yes / no) \n";
        std::cin >> answer;
        if (answer == "yes"){
            if (number == monitors[choice - 1].inventory) {
                monitors.erase(monitors.begin() + choice - 1);
            } else {
                monitors[choice - 1].inventory -= number;
                monitors[choice - 1].price -= cart_item.price;
            }
            admin_wallet += cart_item.price;
            customer_wallet -= cart_item.price;
        } 
        else if (answer == "no"){
            cart.erase(cart.end());
        } 
        else {
            std::cout << "Invalid input ! \n";
            cart.erase(cart.end());
        }
    }
    else {
        std::cout << "Invalid input! \n";
    } 
}

void cart_inventory(){
    std::cout << "Your cart inventory is : \n";
    for(int i = 0; i < cart.size(); i++){
        std::cout << i + 1 << "- " << cart[i].name << "\n";
        std::cout << "Price : " << cart[i].price << "\n";
        std::cout << "Inventory : " << cart[i].inventory << "\n";
        std::cout << "----------------------\n";
    }
}

void shopping_cart() {
    int choice{};
    std::cout << "Enter your choice: \n";
    std::cout << "1- Shopping cart balance \n";
    std::cout << "2- Shopping cart inventory \n";
    std::cin >> choice;
    std::string answer{};
    
    switch (choice) {
        case 1:
            std::cout << "Your shopping cart balance is: " << customer_wallet << std::endl;
            break;
        case 2:
            if (cart.empty()){
                std::cout << "Your shopping cart is empty! \n";
                std::cout << "Do you want to add something to your cart? (yes/no) \n";
                std::cin >> answer; 
                if (answer == "yes") {
                    shop();
                } else if (answer == "no"){
                    return;
                } else{
                    std::cout << "Inavalid input ! \n";
                    return;
                }
            } else if (!cart.empty()){
                cart_inventory();
                std::cout << "Do you want to add something else? (yes / no) \n";
                std::cin >> answer;
                if (answer == "yes") {
                    shop();
                } else if (answer == "no"){
                    return;
                } else {
                    std::cout << "Invalid input !";
                    return;
                }
            }
            break;
        default:
            std::cout << "Invalid input! \n";
    }
}


void customer_menu() {
    while (true){
        std::cout << "customer menu : \n"
                  << "1- Search Product \n"
                  << "2- Show all product \n"
                  << "3- Customer wallet recharge \n"
                  << "4- Shopping cart \n"
                  << "5- Exit \n";
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1:
            search_product();
            break;
        case 2:
            show_product();
            break;
        case 3:
            customer_recharge();
            break;
        case 4 :
            shopping_cart();
            break;
        case 5:
            return;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
}

void main_menu(std::string user_type) {
    if (user_type == "admin") {
        std::string password{};
        do {
            std::cout << "Enter the password: \n";
            std::cin >> password;
            if (password == "admin1admin") {
                admin_menu();
            } else {
                std::cout << "incorrect password! \n";
            }
        } while (password != "admin1admin");
    } else if (user_type == "customer") {
        customer_menu();
    } else {
        std::cout << "Invalid answer! \n";
    }
}

int main(){
    std::string user_type {};
    while(true){
        std::cout << "Are you an admin or customer ? (admin / customer / exit) \n";
        std::cin >> user_type;
        if (user_type == "exit") return 0;
        main_menu(user_type);
    }
}