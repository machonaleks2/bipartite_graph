# Analiza Grafu - Sprawdzanie Dwudzielności

## Opis Projektu
Ten projekt jest programem do sprawdzania, czy zadany graf jest dwudzielny. Dwudzielność grafu oznacza możliwość podziału wierzchołków na dwie grupy, takie że każda krawędź łączy wierzchołki należące do różnych grup.
Na marginesie chciałbym też dodać, że jest to projekt zaliczeniowy z przedmiotu Podstawy Programowania Komputerowego.

Program:
- Wczytuje graf z pliku w formacie listy krawędzi.
- Sprawdza dwudzielność za pomocą algorytmu BFS.
- Zapisuje wyniki do wskazanego pliku wyjściowego.

## Wymagania
- **Kompilator C++**: Zgodny z C++11 lub nowszym. (W kodzie zawarte jest solution ze środowiskiem do visual studio)
- **Doxygen** (opcjonalnie): Do generowania dokumentacji.

## Jak Używać
1. **Kompilacja**:
   ```bash
   g++ main.cpp bipartite.cpp -o bipartite
   ```
2. **Uruchamianie**:
   ```bash
   ./bipartite.exe -i graph.txt -o output.txt
   ```
   - `-i`: Ścieżka do pliku wejściowego.
   - `-o`: Ścieżka do pliku wyjściowego.

3. **Przykład Pliku Wejściowego (`graph.txt`)**:
   ```
   1 2
   2 3
   3 4
   4 1
   ```

4. **Przykład Wyniku (`output.txt`)**:
   ```
   The graph is bipartite.
   Group 1: 1 3
   Group 2: 2 4
   ```

## Generowanie Dokumentacji Doxygen
1. Wygeneruj plik konfiguracyjny:
   ```bash
   doxygen -g
   ```
2. Edytuj `Doxyfile`:
   - Ustaw `INPUT` na ścieżki do plików źródłowych.
   - Ustaw `OUTPUT_DIRECTORY` na katalog wynikowy.
3. Wygeneruj dokumentację:
   ```bash
   doxygen Doxyfile
   ```
4. Dokumentacja w formacie HTML będzie dostępna w katalogu `html/`.

