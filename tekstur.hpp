std::vector<std::vector<Texture>> chara;
std::vector<Texture> bg;
std::vector<Texture> komik;
std::vector<std::string> namachara;
std::vector<std::string> infochara;
std::vector<IntRect> clipchara;

Texture dialogTexture;
Sprite dialogSprite;
Text namaText, dialogText;

Texture autoTexture,autoHoverTexture,autoAktifTexture;
Texture skipTexture,skipHoverTexture,skipAktifTexture,cropCharaTexture;
Sprite autoButton, skipButton, cropChara,chara0;
void initTexture(){
	autoTexture.loadFromFile("resources/auto.png");
	autoHoverTexture.loadFromFile("resources/auto_hover.png");
	autoAktifTexture.loadFromFile("resources/auto_aktif.png");
	skipTexture.loadFromFile("resources/skip.png");
	skipHoverTexture.loadFromFile("resources/skip_hover.png");
	skipAktifTexture.loadFromFile("resources/skip_aktif.png");
	cropCharaTexture.loadFromFile("resources/chara.png");
	autoButton.setTexture(autoTexture);
	skipButton.setTexture(skipTexture);
	cropChara.setTexture(cropCharaTexture);

	dialogTexture.loadFromFile("resources/dialog.png");
	dialogSprite.setTexture(dialogTexture);
	dialogSprite.setOrigin(0,dialogSprite.getLocalBounds().height);
	dialogSprite.setPosition(0,640);
	cropChara.setPosition(dialogSprite.getPosition().x,dialogSprite.getPosition().y-200);
	chara0.setPosition(cropChara.getPosition().x+4,cropChara.getPosition().y+4);
	autoButton.setPosition(dialogSprite.getPosition().x+10,dialogSprite.getPosition().y-45);
	skipButton.setPosition(dialogSprite.getPosition().x+10,dialogSprite.getPosition().y-85);
	namaText.setPosition(dialogSprite.getPosition().x+110,dialogSprite.getPosition().y-195);
	dialogText.setPosition(dialogSprite.getPosition().x+110,dialogSprite.getPosition().y-140);

  	std::ifstream bgconfigloader("bg/texture.cyktconf");
  	if(!bgconfigloader.is_open()){
  	}
  	else{
  		std::string s;
  		while(getline(bgconfigloader,s)){
  			if(s!=""){
				Texture backgroundloader;
				backgroundloader.loadFromFile("bg/"+s);
				bg.push_back(backgroundloader);
			}
		}
		bgconfigloader.close();
	}
	
	std::ifstream characonfigloader("chara/chara.cyktconf");
  	if(!characonfigloader.is_open()){
  	}
  	else{
  		std::string s;
  		while(getline(characonfigloader,s)){
  			if(s!=""){
			  	std::vector<Texture> charaVector;
  				std::ifstream charatextureloader("chara/"+s+"/texture.cyktconf");
			  	if(!charatextureloader.is_open()){
			  	}
			  	else{
			  		std::string x;
			  		while(getline(charatextureloader,x)){
			  			if(x!=""){
			  				Texture charaloader;
			  				charaloader.loadFromFile("chara/"+s+"/"+x);
			  				charaVector.push_back(charaloader);
						}
					}
				}
				chara.push_back(charaVector);
  				int ir1=0, ir2=0, ir3=200, ir4=200;
  				std::string namacharaloader="-";
				std::string infocharaloader="-";
  				std::ifstream charainfoloader("chara/"+s+"/info.cyktconf");
			  	if(!charainfoloader.is_open()){
			  	}
			  	else{
			  		int gs=0;
			  		std::string x;
			  		while(getline(charainfoloader,x)){
			  			if(gs==0){
						  namacharaloader = x;
						}
			  			if(gs==1){
						  std::istringstream(x) >> ir1;
						}
			  			if(gs==2){
						  std::istringstream(x) >> ir2;
						}
			  			if(gs==3){
						  std::istringstream(x) >> ir3;
						}
			  			if(gs==4){
						  std::istringstream(x) >> ir4;
						}
			  			if(gs==5){
						  infocharaloader = x;
						}
			  			gs++;
					}
					charainfoloader.close();
				}
				clipchara.push_back(IntRect(ir1,ir2,ir3,ir4));
				namachara.push_back(namacharaloader);
				infochara.push_back(infocharaloader);
			}
		}
		characonfigloader.close();
	}
}
