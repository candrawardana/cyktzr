#include "header.hpp"
#include "tekstur.hpp"
#include "cerita.hpp"

int main()
{
    // Create the main window
    initTexture();
    initCerita();
    window.setFramerateLimit(60);
    

    Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;
	namaText.setFont(font);
	namaText.setCharacterSize(40);
	dialogText.setFont(font);
	dialogText.setCharacterSize(30);

	String keadaan = "cerita";
    while (window.isOpen())
    {
        // Process events
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseMoved)
            {
                cursorPos.setPosition(Mouse::getPosition(window).x,Mouse::getPosition(window).y);
            }
			if(keadaan=="cerita"){
				prosesPollCerita();
			}
        }
        // Clear screen
        window.clear();
        
        if(keadaan=="menu"){
		}
		if(keadaan=="cerita"){
			prosesCerita(stageMain,subMain);
		}
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
