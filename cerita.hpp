class Cerita{
	public:
		std::string nama;
		std::string dialog;
		int chara0;
		int ekspresi0;
		int chara1;
		int ekspresi1;
		int chara2;
		int ekspresi2;
		int fokus;
		int background;
		int jenis;
		int bgm;
		int sfx;
		int partikel;
		int efek;
		int margin1;
		int margin2;
};

bool loadbg=false;
Sprite chara1;
bool loadchara1=false;
Sprite chara2;
bool loadchara2=false;
Sprite background;
std::string nama;
std::string dialog;

int stageMain=0;
int subMain=0;

std::vector<std::vector<Cerita>> cerita;
initCerita(){
	std::ifstream ceritaconfigloader("stage/stage.cyktconf");
  	if(!ceritaconfigloader.is_open()){
  	}
  	else{
  		std::string x;
  		std::vector<Cerita> ceritaloader;
  		while(getline(ceritaconfigloader,x)){
		  	std::ifstream fi("stage/"+x+"/cerita.cyktconf");
		  	int sg=1;
		  	if(!fi.is_open()){
		  	}
		  	else{
			  	std::string s;
			  	Cerita detailloader;
		  		while(getline(fi,s)){
		  			if(sg==1){
		  				if(s!="-")
			  				detailloader.nama = s;
					}
		  			if(sg==2){
		  				if(s!="-")
			  				detailloader.dialog = s;
					}
		  			if(sg==3){
		  				if(s=="-")
			  				detailloader.chara0 = -1;
				  		else
					  		std::istringstream(s) >> detailloader.chara0;
					}
		  			if(sg==4){
		  				if(s=="-")
			  				detailloader.ekspresi0 = -1;
				  		else
					  		std::istringstream(s) >> detailloader.ekspresi0;
					}
		  			if(sg==5){
		  				if(s=="-")
			  				detailloader.chara1 = -1;
				  		else
					  		std::istringstream(s) >> detailloader.chara1;
					}
		  			if(sg==6){
		  				if(s=="-")
			  				detailloader.ekspresi1 = -1;
				  		else
					  		std::istringstream(s) >> detailloader.ekspresi1;
					}
		  			if(sg==7){
		  				if(s=="-")
			  				detailloader.chara2 = -1;
				  		else
					  		std::istringstream(s) >> detailloader.chara2;
					}
		  			if(sg==8){
		  				if(s=="-")
			  				detailloader.ekspresi2 = -1;
				  		else
					  		std::istringstream(s) >> detailloader.ekspresi2;
					}
		  			if(sg==9){
		  				if(s=="-")
			  				detailloader.fokus = -1;
				  		else
					  		std::istringstream(s) >> detailloader.fokus;
					}
		  			if(sg==10){
		  				if(s=="-")
			  				detailloader.background = -1;
				  		else
					  		std::istringstream(s) >> detailloader.background;
					}
		  			if(sg==11){
		  				if(s=="-")
			  				detailloader.jenis = -1;
				  		else
					  		std::istringstream(s) >> detailloader.jenis;
					}
		  			if(sg==12){
		  				if(s=="-")
			  				detailloader.bgm = -1;
				  		else
					  		std::istringstream(s) >> detailloader.bgm;
					}
		  			if(sg==13){
		  				if(s=="-")
			  				detailloader.sfx = -1;
				  		else
					  		std::istringstream(s) >> detailloader.sfx;
					}
		  			if(sg==14){
		  				if(s=="-")
			  				detailloader.partikel = -1;
				  		else
					  		std::istringstream(s) >> detailloader.partikel;
					}
		  			if(sg==15){
		  				if(s=="-")
			  				detailloader.efek = -1;
				  		else
					  		std::istringstream(s) >> detailloader.efek;
					}
		  			if(sg==16){
		  				if(s=="-")
			  				detailloader.margin1 = 200;
				  		else
					  		std::istringstream(s) >> detailloader.margin1;
					}
		  			if(sg==17){
		  				if(s=="-")
			  				detailloader.margin2 = 200;
				  		else
					  		std::istringstream(s) >> detailloader.margin2;
					}
		  			if(sg==17){
		  				sg=0;
		  				ceritaloader.push_back(detailloader);
					}
				  	sg+=1;
				}
				fi.close();
		  	}
  		}
		cerita.push_back(ceritaloader);
		ceritaconfigloader.close();
  	}
}

bool loadCerita = false,autoCerita = false, skipCerita = false;

prosesCerita(int stage, int detail){
	if(loadCerita==false){
		dialog = cerita[stage][detail].dialog;
		std::string prosesNama = "";
		if(cerita[stage][detail].fokus==0 && cerita[stage][detail].chara0!=-1)
			prosesNama = namachara[cerita[stage][detail].chara0];
		if(cerita[stage][detail].fokus==1 && cerita[stage][detail].chara1!=-1)
			prosesNama = namachara[cerita[stage][detail].chara1];
		if(cerita[stage][detail].fokus==2 && cerita[stage][detail].chara2!=-1)
			prosesNama = namachara[cerita[stage][detail].chara2];
		if(cerita[stage][detail].nama!="")
			prosesNama = cerita[stage][detail].nama;
		nama = prosesNama;
		loadchara1=false;
		if(cerita[stage][detail].chara1!=-1){
			chara1.setTexture((chara[cerita[stage][detail].chara1][cerita[stage][detail].ekspresi1]));
			loadchara1=true;
			chara1.setOrigin(chara1.getLocalBounds().width/2,chara1.getLocalBounds().height);
			chara1.setScale(responsif(chara1,600,980));
			chara1.setPosition(1024/4,640+cerita[stage][detail].margin1);
		}
		loadchara2=false;
		if(cerita[stage][detail].chara2!=-1){
			chara2.setTexture((chara[cerita[stage][detail].chara2][cerita[stage][detail].ekspresi2]));
			loadchara2=true;
			chara2.setOrigin(chara2.getLocalBounds().width/2,chara2.getLocalBounds().height);
			chara2.setScale(responsif(chara2,600,980));
			chara2.setPosition(1024*3/4,640+cerita[stage][detail].margin2);
		}
		dialogText.setString(dialog);
		namaText.setString(nama);
		loadbg=false;
		if(cerita[stage][detail].background!=-1){
			loadbg=true;
			background.setTexture(bg[cerita[stage][detail].background]);
			background.setScale(pas(background,1024,640));
		}
		if(cerita[stage][detail].chara0==-1){
			if(cerita[stage][detail].fokus==1){
				chara0.setTexture(chara[cerita[stage][detail].chara1][cerita[stage][detail].ekspresi1]);
				chara0.setTextureRect(clipchara[cerita[stage][detail].chara1]);
			}
			if(cerita[stage][detail].fokus==2){
				chara0.setTexture(chara[cerita[stage][detail].chara2][cerita[stage][detail].ekspresi2]);
				chara0.setTextureRect(clipchara[cerita[stage][detail].chara2]);
			}
		}
		else{
			chara0.setTexture(chara[cerita[stage][detail].chara0][cerita[stage][detail].ekspresi0]);
			chara0.setTextureRect(clipchara[cerita[stage][detail].chara0]);
		}
		chara0.setScale(responsif(chara0,93,93));

		loadCerita=true;
	}
	else{
		if(loadbg){
			window.draw(background);
		}
		if(loadchara1){
			window.draw(chara1);
		}
		if(loadchara2){
			window.draw(chara2);
		}
		window.draw(dialogSprite);
		window.draw(cropChara);
		window.draw(chara0);
		window.draw(autoButton);
		window.draw(skipButton);
		window.draw(dialogText);
		window.draw(namaText);
	}
}

prosesPollCerita(){
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
		if(cursorPos.getGlobalBounds().intersects(autoButton.getGlobalBounds())){
			autoCerita=!autoCerita;
		}
		else if(cursorPos.getGlobalBounds().intersects(skipButton.getGlobalBounds())){
			skipCerita=!skipCerita;
		}
		else{
			if(cerita[stageMain].size()>subMain){
				subMain++;
			}
			else{
				if(cerita.size()>stageMain){
					stageMain++;
					subMain=0;
				}
			}
		}
	}
	if(cursorPos.getGlobalBounds().intersects(autoButton.getGlobalBounds())){
		autoButton.setTexture(autoHoverTexture);
	}
	else{
		if(autoCerita)
			autoButton.setTexture(autoAktifTexture);
		else
			autoButton.setTexture(autoTexture);
	}
	if(cursorPos.getGlobalBounds().intersects(skipButton.getGlobalBounds())){
		skipButton.setTexture(skipHoverTexture);
	}
	else{
		if(skipCerita)
			skipButton.setTexture(skipAktifTexture);
		else
			skipButton.setTexture(skipTexture);
	}
}
