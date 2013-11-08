# Class Diagram

## Aufgabe:
> Analysieren Sie Ihre Use Cases und leiten Sie daraus Analyseklassen ab

## Classes:
| Klassenname   | Beschreibung                                                 |
| ------------- | ------------------------------------------------------------ |
| Steuerung     | steuert den Ablauf, weist "Dosierer" an, überwacht die Waage |
| Rezeptbuch    | wird beim Starten mit allen mischbaren Rezepten geladen      |
| Rezept        | enthält alle notwendigen Rezeptschritte                      |
| Rezeptschritt | enthält "Zutat" und Menge                                    |
| Dosierer      | gibt "Zutat" in Mischbehälters                               |
| Mixer         | mischt, entleert, reinigt                                    |
| Stampfer      | stampft                                                      |
| Waage         | misst den Inhalt des Mischbehälters                          |
