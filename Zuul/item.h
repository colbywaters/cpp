/*
 * Zuul Birthday Party implementation
 *
 * File: item.h
 * Description: Item definition
 *
 * Colby Waters
 * 12/18/2022
 */

/*
 * Item - contains an information about an item.
 */
class Item {
public:
	char description[512];
	
	Item(const char* desc) {
        strcpy(description, desc);
	}
	
	const char* getDescription() {
		return description;
	}
};
