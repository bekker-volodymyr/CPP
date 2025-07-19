using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace ConsoleApp342
{
    public static class DictionaryStorage
    {
        private static string folder = "Dictionaries";

        public static void Save(DictionaryData dict)
        {
            Directory.CreateDirectory(folder);
            string path = Path.Combine(folder, dict.Type + ".json");
            File.WriteAllText(path, System.Text.Json.JsonSerializer.Serialize(dict, new JsonSerializerOptions { WriteIndented = true }));
        }

        public static DictionaryData Load(string type)
        {
            string path = Path.Combine(folder, type + ".json");
            if (File.Exists(path))
            {
                string json = File.ReadAllText(path);
                return System.Text.Json.JsonSerializer.Deserialize<DictionaryData>(json);
            }
            return new DictionaryData { Type = type };
        }

        public static void ExportWord(DictionaryData dict, string word)
        {
            if (dict.Entries.TryGetValue(word, out var entry))
            {
                string exportFolder = "Exports";
                Directory.CreateDirectory(exportFolder);
                string filename = Path.Combine(exportFolder, word + ".txt");
                File.WriteAllText(filename, $"{entry.Word}: {string.Join(", ", entry.Translations)}");
                Console.WriteLine($"Word '{word}' exported to file '{filename}'");
            }
            else
            {
                Console.WriteLine("Word not found in dictionary.");
            }
            Console.WriteLine("Press any key...");
            Console.ReadKey();
        }

        public static void ExportToTextFile(DictionaryData dictionary)
        {
            string exportFolder = "Exports";
            Directory.CreateDirectory(exportFolder);
            string filename = Path.Combine(exportFolder, dictionary.Type + "_export.txt");
            using (StreamWriter writer = new StreamWriter(filename))
            {
                foreach (var entry in dictionary.Entries.Values)
                {
                    writer.WriteLine($"{entry.Word} - {string.Join(", ", entry.Translations)}");
                }
            }

            Console.WriteLine($"Dictionary exported to file: {filename}");
            Console.WriteLine("Press any key...");
            Console.ReadKey();
        }

        public static void ExportToCsv(DictionaryData dict)
        {
            string exportFolder = "Exports";
            Directory.CreateDirectory(exportFolder);
            string filename = Path.Combine(exportFolder, dict.Type + ".csv");

            using (StreamWriter writer = new StreamWriter(filename))
            {
                writer.WriteLine("Word,Translations");
                foreach (var entry in dict.Entries.Values)
                {
                    writer.WriteLine($"\"{entry.Word}\",\"{string.Join(";", entry.Translations)}\"");
                }
            }

            Console.WriteLine($"Dictionary '{dict.Type}' exported to CSV file '{filename}'");
            Console.WriteLine("Press any key...");
            Console.ReadKey();

            try
            {
                System.Diagnostics.Process.Start(new System.Diagnostics.ProcessStartInfo
                {
                    FileName = filename,
                    UseShellExecute = true
                });
            }
            catch (Exception ex)
            {
                Console.WriteLine("Could not open file automatically: " + ex.Message);
            }
        }

        public static void ImportFromCsv(DictionaryData dict, string csvPath)
        {
            if (!File.Exists(csvPath))
            {
                Console.WriteLine("File not found.");
                return;
            }

            using (StreamReader reader = new StreamReader(csvPath))
            {
                string header = reader.ReadLine(); 
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    var parts = line.Split(',');
                    if (parts.Length >= 2)
                    {
                        string word = parts[0].Trim('"');
                        string[] translations = parts[1].Trim('"').Split(';');

                        if (dict.Entries.ContainsKey(word))
                        {
                            dict.Entries[word].Translations.AddRange(translations);
                        }
                        else
                        {
                            dict.Entries[word] = new DictionaryEntry { Word = word, Translations = new List<string>(translations) };
                        }
                    }
                }
            }

            Console.WriteLine("Import complete. Press any key....");
            Console.ReadKey();
        }
    }
}
