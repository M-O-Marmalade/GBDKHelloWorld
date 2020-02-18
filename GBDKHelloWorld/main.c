#include <gb/gb.h>
#include <stdio.h>
#include "wiggleSprite.c"

int main() {
	//printf("HELLO LITTLE WIGGLER\n");
	//UINT16 d = 3;
	//delay(d);
	//printf("New Print!");
	UINT8 counter = 0;
	UINT8 currentSpriteIndex = 0;
	UINT8 whileCounter1 = 0;
	set_sprite_data(0, 3, wiggler);	
	set_sprite_tile(0, 0);
	move_sprite(0, 88, 78);

	SHOW_SPRITES;

	while (1) {
		while (whileCounter1 != 20){
			switch (joypad()) {
			case J_UP | J_LEFT:
				scroll_sprite(0, -1, -1);
				break;
			case J_UP:
				scroll_sprite(0, 0, -1);
				break;	
			case J_UP | J_RIGHT:
				scroll_sprite(0, 1, -1);
				break;
			case J_RIGHT:
				scroll_sprite(0, 1, 0);
				break;
			case J_DOWN | J_RIGHT:
				scroll_sprite(0, 1, 1);
				break;
			case J_DOWN:
				scroll_sprite(0, 0, 1);
				break;
			case J_DOWN | J_LEFT:
				scroll_sprite(0, -1, 1);
				break;
			case J_LEFT:
				scroll_sprite(0, -1, 0);
				break;			
			}

			set_sprite_tile(0, currentSpriteIndex);
			delay(10);
			whileCounter1++;
		}

		whileCounter1 = 0;

		if (counter == 0) {
			currentSpriteIndex = 0;
			counter++;
		}
		else if (counter == 1) {
			currentSpriteIndex = 1;
			counter++;
		}
		else if (counter == 2) {
			currentSpriteIndex = 0;
			counter++;
		}
		else {
			currentSpriteIndex = 2;
			counter = 0;
		}

		set_sprite_tile(0, currentSpriteIndex);
	}
}
