#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/zakaz/source/repos/2/2/Menu.h"
#include "/Users/zakaz/source/repos/2/2/time.h"
#include "/Users//zakaz/source//repos//2/2/time.cpp"
#include "/Users/zakaz/source/repos/2/2/Menu.cpp"
#include "/Users/zakaz/source/repos/2/2/Read_Output.h"
#include "/Users/zakaz/source/repos/2/2/Read_Output.cpp"
#include <iostream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(ValidFormatTime)
		{
			std::vector<std::string> Cases
			{
				"12:00",
				"1:00",
				"01:00"
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Time::ValidateTime(Cases[i]);
				Assert::IsTrue(result);
			}
		}

		TEST_METHOD(InvalidFormatTime)
		{
			std::vector<std::string> Cases
			{
				"60:240",
				"ab:cd",
				"wrong"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Time::InvalidTime(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatName)
		{
			std::vector<std::string> Cases
			{
				"Лапша",
				"Курица",
				"Пельмени",
				"Борщ",
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Menu::ValidateName(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatName)
		{
			std::vector<std::string> Cases
			{
				"@-01.9ё",
				"19:84",
				"dsadas"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Menu::InvalidName(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatPrice)
		{
			std::vector<double> Cases
			{
				23.0,
				1.5,
				0.001,
				11.9
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Menu::ValidatePrice(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatPrice)
		{
			std::vector<double> Cases
			{
				-1.5,
				-23.65
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Menu::InvalidPrice(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}

		// TODO: test WriteMenu
		TEST_METHOD(ValidWriteMenu)
		{
			std::istringstream input("\"Лапша\" 12.25 12:00");
			Menu menu;

			std::ostringstream expected_output;
			expected_output << "Название блюда: " << menu.GetName() << std::endl;
			expected_output << "Цена: " << menu.GetPrice() << std::endl;
			Time menu_time = menu.GetMenuTime();
		}

		// TODO: test WriteTime
		TEST_METHOD(ValidWriteTime)
		{
			std::istringstream input("12:00");
			Time menu_time;
			menu_time.ReadTime(input);
			std::ostringstream expected_output;
			expected_output << "Время приготовления: " << menu_time.GetHours() << ":" << menu_time.GetMinutes() << std::endl;
		}

		TEST_METHOD(ValidTestMenu)
		{
			std::istringstream input(" \"Пельмени\" 10.5 02:20");

			Menu menu = Menu::create(input);

			Assert::AreEqual(std::string("Пельмени"), menu.GetName());
			Assert::AreEqual(std::string("10.5"), menu.GetPrice());

			Time time = menu.GetMenuTime();
			Assert::AreEqual(2, time.GetHours());
			Assert::AreEqual(20, time.GetMinutes());
		}

		TEST_METHOD(InvalidTestMenu)
		{
			std::vector<std::string> cases
			{
				"1231 13123.1 3213 1 fadasd",
				"aaad 131 vdvs a1",
				"da312 das 123"
			};
			for (int i = 0; i < cases.size(); i++)
			{
				std::istringstream input(cases[i]);
				try
				{
					Menu menu;
					
					throw std::runtime_error("Error in runtime");
				}
				catch (const std::runtime_error& e)
				{
					std::cerr << "Error Message: " << e.what() << std::endl;
				}
			}
		}
	};
}
