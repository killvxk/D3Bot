#include "stdafx.h"
#include "fight.h"




void BotHeal()
{ 
	int allcolors;

	allcolors = FindAllColor(&globalscreengrab, 0x00650000, 0x00FF1F1F, 655, 214, 757, 221);

	if((allcolors < leavehp) || ((allcolors < dangerleavehp) && (healdanger == 1)))
	{

		keybd_event('Q', 0,0,0);
		keybd_event('Q', 0,KEYEVENTF_KEYUP,0);
		Sleep(20);

		if(healbutton1 != 0)
		{
			if(healbutton1 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton1 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton1 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(healbutton1 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(100);
		}

		if(healbutton2 != 0)
		{
			if(healbutton2 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton2 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton2 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(healbutton2 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(100);
		}

		if(healbutton3 != 0)
		{
			if(healbutton3 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton3 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton3 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(healbutton3 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(100);
		}

		if(healbutton4 != 0)
		{
			if(healbutton4 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton4 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(healbutton4 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(healbutton4 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(100);
		}

		healdanger = 0;

		if(BotDeathCount > maxdeathcount - 1)
		{
			logprint("Ќова€ игра (ѕричина - прогноз превышени€ максимального количества смертей)", 0);
			BotNewGame();
		}
	}
	else if(allcolors < skillhp)
	{
		healdanger = 0;

		keybd_event('Q', 0,0,0);
		keybd_event('Q', 0,KEYEVENTF_KEYUP,0);
		Sleep(20);

		if(healloop == 0)
		{
			if(healbutton1 != 0)
			{
				if(healbutton1 == 1)
				{
					keybd_event(49, 0,0,0);
					keybd_event(49, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton1 == 2)
				{
					keybd_event(50, 0,0,0);
					keybd_event(50, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton1 == 3)
				{
					keybd_event(51, 0,0,0);
					keybd_event(51, 0,KEYEVENTF_KEYUP,0);
				} 
				else if(healbutton1 == 4)
				{
					keybd_event(52, 0,0,0);
					keybd_event(52, 0,KEYEVENTF_KEYUP,0);
				}

				Sleep(100);
			}
			healloop++;

			if(healloop == 4)
			{
				healloop = 0;
			}

			return;
		}

		if(healloop == 1)
		{
			if(healbutton2 != 0)
			{
				if(healbutton2 == 1)
				{
					keybd_event(49, 0,0,0);
					keybd_event(49, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton2 == 2)
				{
					keybd_event(50, 0,0,0);
					keybd_event(50, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton2 == 3)
				{
					keybd_event(51, 0,0,0);
					keybd_event(51, 0,KEYEVENTF_KEYUP,0);
				} 
				else if(healbutton2 == 4)
				{
					keybd_event(52, 0,0,0);
					keybd_event(52, 0,KEYEVENTF_KEYUP,0);
				}

				Sleep(100);
			}

			healloop++;

			if(healloop == 4)
			{
				healloop = 0;
			}

			return;
		}

		if(healloop == 2)
		{
			if(healbutton3 != 0)
			{
				if(healbutton3 == 1)
				{
					keybd_event(49, 0,0,0);
					keybd_event(49, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton3 == 2)
				{
					keybd_event(50, 0,0,0);
					keybd_event(50, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton3 == 3)
				{
					keybd_event(51, 0,0,0);
					keybd_event(51, 0,KEYEVENTF_KEYUP,0);
				} 
				else if(healbutton3 == 4)
				{
					keybd_event(52, 0,0,0);
					keybd_event(52, 0,KEYEVENTF_KEYUP,0);
				}

				Sleep(100);
			}
			healloop++;

			if(healloop == 4)
			{
				healloop = 0;
			}

			return;
		}

		if(healloop == 3)
		{
			if(healbutton4 != 0)
			{
				if(healbutton4 == 1)
				{
					keybd_event(49, 0,0,0);
					keybd_event(49, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton4 == 2)
				{
					keybd_event(50, 0,0,0);
					keybd_event(50, 0,KEYEVENTF_KEYUP,0);
				}
				else if(healbutton4 == 3)
				{
					keybd_event(51, 0,0,0);
					keybd_event(51, 0,KEYEVENTF_KEYUP,0);
				} 
				else if(healbutton4 == 4)
				{
					keybd_event(52, 0,0,0);
					keybd_event(52, 0,KEYEVENTF_KEYUP,0);
				}

				Sleep(100);
			}

			healloop++;

			if(healloop == 4)
			{
				healloop = 0;
			}

			return;
		}

	}
	else if(allcolors < potionhp)
	{
		healdanger = 0;
		keybd_event('Q', 0,0,0);
		keybd_event('Q', 0,KEYEVENTF_KEYUP,0);
	}

	
	if(hplastcount >= allcolors + 3)
	{
		CaptureScreen(&globalscreengrab);
		if(FindDieColor(&globalscreengrab) == 1)
		{
			hpminuscount = hpminuscount + 2;
		}
		else
		{
			hpminuscount++;
		}
		
		hpminustime = time(NULL);
		if(hpminuscount >= 7)
		{
			int randmovex = rand() % 50 + -50;
			int randmovey = rand() % 50 + -50;
			if((FindFollowColor(&globalscreengrab) == 1))
			{

				SetCursorPosition(rx + randmovex,ry + randmovey);
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,10);

				if((movebutton != 0) && (DetectPlayersColors(&globalscreengrab, 400, 200, 650, 450) == 0))
				{
					MoveButton();
				}
				else
				{
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
					Sleep(500);
				}
			}
			else
			{
				SetCursorPosition(200 + randmovex,200 + randmovey);
				if(movebutton != 0)
				{
					if(movebutton == 1)
					{
						keybd_event(49, 0,0,0);
						keybd_event(49, 0,KEYEVENTF_KEYUP,0);
					}
					else if(movebutton == 2)
					{
						keybd_event(50, 0,0,0);
						keybd_event(50, 0,KEYEVENTF_KEYUP,0);
					}
					else if(movebutton == 3)
					{
						keybd_event(51, 0,0,0);
						keybd_event(51, 0,KEYEVENTF_KEYUP,0);
					} 
					else if(movebutton == 4)
					{
						keybd_event(52, 0,0,0);
						keybd_event(52, 0,KEYEVENTF_KEYUP,0);
					}
					else if(movebutton == 5)
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
						mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
					}
					else if(movebutton == 6)
					{
						mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
						mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
					}
				}
				else
				{
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
					Sleep(500);
				}
			}
			hpminuscount = 0;
		}
	}
	else
	{
		if((hpminustime + 1 <= time(NULL)))
		{
			hpminuscount = 0;
		}
	}

	hplastcount = allcolors;

}







void BotAttack()
{

	AttackCount++;
	SkillCount++;
	BuffCount++;

	if(noauth == 1)
	{
		Sleep(5000);
	}

	if( ((((ry + 50 < 530) && (rx + 25 > 70)) || ((ry + 50 > 620) && (ry + 50 < 675))) || (rx + 25 > 300)) && ((((ry + 50 < 530) && (rx + 25 > 65)) || ((ry + 50 > 620) && (ry + 50 < 675))) || (rx + 25 > 300)) )
	{
		SetCursorPosition(rx + 25,ry + 50);
	}

	if(BuffCount > buffduration)
	{
		BuffCount = 0;
		if(buffbutton != 0)
		{
			if(buffbutton == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(buffbutton == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(buffbutton == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(buffbutton == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}
			else if(buffbutton == 5)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			}
			else if(buffbutton == 6)
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			}
		}
	}



	if(AttackCount > secondaryduration)
	{
		AttackCount = 0;
		if(MainAttack == 1)
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
			if(secondaryattackpause > 0)
			{
				int secondaryattackpausecount = 0;
				while(secondaryattackpausecount < (secondaryattackpause * (SleepTime / 10)))
				{
					CaptureScreen(&globalscreengrab);
					BotHeal();
					if(FindAttackColor(&globalscreengrab) == 1)
					{
						if( ((((ry + 50 < 530) && (rx + 25 > 70)) || ((ry + 50 > 620) && (ry + 50 < 675))) || (rx + 25 > 300)) && ((((ry + 50 < 530) && (rx + 25 > 65)) || ((ry + 50 > 620) && (ry + 50 < 675))) || (rx + 25 > 300)) )
						{
							SetCursorPosition(rx + 25,ry + 50);
						}
					}
					else
					{
						break;
					}

					secondaryattackpausecount++;

					Sleep(SleepTime);
				}
			}
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
		}
		else if(MainAttack == 0)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			if(secondaryattackpause > 0)
			{
				int secondaryattackpausecount = 0;
				while(secondaryattackpausecount < (secondaryattackpause * (SleepTime / 10)))
				{
					CaptureScreen(&globalscreengrab);
					BotHeal();
					if(FindAttackColor(&globalscreengrab) == 1)
					{
						if( ((((ry + 50 < 530) && (rx + 25 > 70)) || ((ry + 50 > 620) && (ry + 50 < 675))) || (rx + 25 > 300)) && ((((ry + 50 < 530) && (rx + 25 > 65)) || ((ry + 50 > 620) && (ry + 50 < 675))) || (rx + 25 > 300)) )
						{
							SetCursorPosition(rx + 25,ry + 50);
						}
					}
					else
					{
						break;
					}

					secondaryattackpausecount++;

					Sleep(SleepTime);
				}
			}
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
		}

		Sleep(secondaryattackcooldown);
	}
	else
	{
		if(MainAttack == 1)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
		}
		else if(MainAttack == 0)
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
		}

		Sleep(mainattackcooldown);
	}

	if(SkillCount >= attackskillduration)
	{
		SkillCount = 0;

		if(attackbutton1 != 0)
		{
			if(attackbutton1 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton1 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton1 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(attackbutton1 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(30);
		}

		if(attackbutton2 != 0)
		{
			if(attackbutton2 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton2 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton2 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(attackbutton2 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(30);
		}

		if(attackbutton3 != 0)
		{
			if(attackbutton3 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton3 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton3 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(attackbutton3 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(30);
		}

		if(attackbutton4 != 0)
		{
			if(attackbutton4 == 1)
			{
				keybd_event(49, 0,0,0);
				keybd_event(49, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton4 == 2)
			{
				keybd_event(50, 0,0,0);
				keybd_event(50, 0,KEYEVENTF_KEYUP,0);
			}
			else if(attackbutton4 == 3)
			{
				keybd_event(51, 0,0,0);
				keybd_event(51, 0,KEYEVENTF_KEYUP,0);
			} 
			else if(attackbutton4 == 4)
			{
				keybd_event(52, 0,0,0);
				keybd_event(52, 0,KEYEVENTF_KEYUP,0);
			}

			Sleep(30);
		}

	}
	botattackcount++;
	if(botattackcount > 500)
	{
		BotNewGame();
	}

}








void BotFollowPlayer(int startx, int starty)
{

	if(followcount == 1000)
	{
		followcount = 0;
		BotNewGame();
		return;
	}
	else
	{
		followcount++;
	}

	if(noauth == 1)
	{
		Sleep(5000);
	}

	if(DetectPlayersColors(&globalscreengrab, 440, 220, 580, 400) == 1)
	{
		return;
	}


	randomfollow();

	
	if(
		(ry + randomfollowy < 680) &&
		(((rx + randomfollowx > 300) || (ry + randomfollowy < 500)) &&
		((rx + randomfollowx > 70) || (ry + randomfollowy > 390))))
	{

	}
	else
	{

		randomfollowx = 0;
		randomfollowy = 0;
		if(
			(ry + randomfollowy < 680) &&
			(((rx + randomfollowx > 300) || (ry + randomfollowy < 500)) &&
			((rx + randomfollowx > 70) || (ry + randomfollowy > 390))))
		{

		}
		else
		{
			return;
		}

	}


	SetCursorPosition(rx + randomfollowx,ry + randomfollowy);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )

	if( ((rx + randomfollowx > 100) && (rx + randomfollowx < 924)) && ((ry + randomfollowy > 100) && (ry + randomfollowy < 600)))
	{
		//если союзники достаточно близко к нам - ничего не делаем
	}
	else if((movebutton != 0) && (DetectPlayersColors(&globalscreengrab, 200, 200, 820, 550) == 0))
	{
		MoveButton();
	}

	return;

}