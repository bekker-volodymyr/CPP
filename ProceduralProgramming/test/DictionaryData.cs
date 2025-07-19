namespace ConsoleApp342
{
    public class DictionaryData
    {
        public string Type { get; set; }
        public Dictionary<string, DictionaryEntry> Entries { get; set; } = new Dictionary<string, DictionaryEntry>();
    }
}
