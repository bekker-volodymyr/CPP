using ConsoleApp342;

namespace СonsoleApp342
{
    class Program
    {
        static void Main(string[] args)
        {
            MainMenu();
        }

        static void MainMenu()
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine("=== DICTIONARY ===");
                Console.WriteLine("1. Create a dictionary");
                Console.WriteLine("2. Download dictionary");
                Console.WriteLine("3. Exit");
                Console.Write("Your choice: ");
                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        CreateDictionary();
                        break;
                    case "2":
                        LoadDictionary();
                        break;
                    case "3":
                        return;
                    default:
                        Console.WriteLine("Invalid selection. Press any key...");
                        Console.ReadKey();
                        break;
                }
            }
        }

        static void CreateDictionary()
        {
            Console.Write("Enter the dictionary type (e.g. English-Ukrainian): ");
            string type = Console.ReadLine();
            var dictionary = new DictionaryData { Type = type };
            DictionaryStorage.Save(dictionary);
            Console.WriteLine("Dictionary created. Press any key...");
            Console.ReadKey();
        }

        static void LoadDictionary()
        {
            Console.Write("Введіть тип словника для завантаження: ");
            string type = Console.ReadLine();
            var dictionary = DictionaryStorage.Load(type);
            Console.WriteLine($"Словник '{dictionary.Type}' завантажено. Записи: {dictionary.Entries.Count}");
            DictionaryMenu(dictionary);
        }

        static void DictionaryMenu(DictionaryData dictionary)
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine($"=== Словник: {dictionary.Type} ===");
                Console.WriteLine("1. Додати слово та переклад");
                Console.WriteLine("2. Замінити переклади слова");
                Console.WriteLine("3. Видалити слово або переклад");
                Console.WriteLine("4. Шукати переклад слова");
                Console.WriteLine("5. Експортувати слово у файл");
                Console.WriteLine("6. Експортувати словник у текстовий файл");
                Console.WriteLine("7. Експортувати словник у CSV-файл");
                Console.WriteLine("8. Імпортувати словник з CSV-файлу");
                Console.WriteLine("9. Повернутися до головного меню");
                Console.Write("Ваш вибір: ");
                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        AddWord(dictionary);
                        break;
                    case "2":
                        ReplaceTranslation(dictionary);
                        break;
                    case "3":
                        DeleteWordOrTranslation(dictionary);
                        break;
                    case "4":
                        SearchTranslation(dictionary);
                        break;
                    case "5":
                        ExportWord(dictionary);
                        break;
                    case "6":
                        DictionaryStorage.ExportToTextFile(dictionary);
                        break;
                    case "7":
                        DictionaryStorage.ExportToCsv(dictionary);
                        break;
                    case "8":
                        Console.Write("Введіть шлях до CSV-файлу: ");
                        string path = Console.ReadLine();
                        DictionaryStorage.ImportFromCsv(dictionary, path);
                        break;
                    case "9":
                        DictionaryStorage.Save(dictionary);
                        return;
                    default:
                        Console.WriteLine("Невірний вибір. Натисніть будь-яку клавішу...");
                        Console.ReadKey();
                        break;
                }
            }
        }

        static void AddWord(DictionaryData dictionary)
        {
            Console.Write("Введіть слово: ");
            string word = Console.ReadLine();
            Console.Write("Введіть переклад (можна через кому кілька): ");
            string translationInput = Console.ReadLine();
            var translations = new List<string>(translationInput.Split(",", StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries));

            if (dictionary.Entries.ContainsKey(word))
            {
                dictionary.Entries[word].Translations.AddRange(translations);
            }
            else
            {
                dictionary.Entries[word] = new DictionaryEntry { Word = word, Translations = translations };
            }

            Console.WriteLine("Слово додано. Натисніть будь-яку клавішу...");
            Console.ReadKey();
        }

        static void ReplaceTranslation(DictionaryData dictionary)
        {
            Console.Write("Введіть слово для редагування: ");
            string word = Console.ReadLine();

            if (!dictionary.Entries.ContainsKey(word))
            {
                Console.WriteLine("Слово не знайдено. Натисніть будь-яку клавішу...");
                Console.ReadKey();
                return;
            }

            Console.WriteLine("Поточні переклади: " + string.Join(", ", dictionary.Entries[word].Translations));
            Console.Write("Введіть нові переклади (через кому): ");
            string newTranslations = Console.ReadLine();
            dictionary.Entries[word].Translations = new List<string>(newTranslations.Split(",", StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries));

            Console.WriteLine("Переклади оновлено. Натисніть будь-яку клавішу...");
            Console.ReadKey();
        }

        static void DeleteWordOrTranslation(DictionaryData dictionary)
        {
            Console.Write("Введіть слово для видалення або редагування: ");
            string word = Console.ReadLine();

            if (!dictionary.Entries.ContainsKey(word))
            {
                Console.WriteLine("Слово не знайдено. Натисніть будь-яку клавішу...");
                Console.ReadKey();
                return;
            }

            Console.WriteLine("Поточні переклади: " + string.Join(", ", dictionary.Entries[word].Translations));
            Console.WriteLine("1. Видалити усе слово разом з перекладами");
            Console.WriteLine("2. Видалити окремий переклад");
            Console.Write("Ваш вибір: ");
            string subChoice = Console.ReadLine();

            switch (subChoice)
            {
                case "1":
                    dictionary.Entries.Remove(word);
                    Console.WriteLine("Слово видалено.");
                    break;
                case "2":
                    Console.Write("Введіть переклад для видалення: ");
                    string toRemove = Console.ReadLine();
                    var translations = dictionary.Entries[word].Translations;
                    if (translations.Contains(toRemove))
                    {
                        if (translations.Count == 1)
                        {
                            Console.WriteLine("Неможливо видалити останній переклад слова.");
                        }
                        else
                        {
                            translations.Remove(toRemove);
                            Console.WriteLine("Переклад видалено.");
                        }
                    }
                    else
                    {
                        Console.WriteLine("Переклад не знайдено.");
                    }
                    break;
                default:
                    Console.WriteLine("Невірний вибір.");
                    break;
            }

            Console.WriteLine("Натисніть будь-яку клавішу...");
            Console.ReadKey();
        }

        static void SearchTranslation(DictionaryData dictionary)
        {
            Console.Write("Введіть слово для пошуку: ");
            string word = Console.ReadLine();

            if (dictionary.Entries.TryGetValue(word, out var entry))
            {
                Console.WriteLine($"Переклади слова '{word}': {string.Join(", ", entry.Translations)}");
            }
            else
            {
                Console.WriteLine("Слово не знайдено у словнику.");
            }

            Console.WriteLine("Натисніть будь-яку клавішу...");
            Console.ReadKey();
        }

        static void ExportWord(DictionaryData dictionary)
        {
            Console.Write("Введіть слово для експорту: ");
            string word = Console.ReadLine();
            DictionaryStorage.ExportWord(dictionary, word);
        }
    }
}
