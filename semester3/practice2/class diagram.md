# Class Diagram

## Aufgabe:
> Analysieren Sie Ihre Use Cases und leiten Sie daraus Analyseklassen ab

## Classes:
Cocktailmischer
	steuert den Ablauf, weist "Dosierer" an, überwacht die Waage
Rezeptbuch
	wird beim Starten mit allen mischbaren Rezepten geladen
Rezept
	enthält alle notwendigen Rezeptschritte
Rezeptschritt
	enthält "Zutat" und Menge
"Dosierer" -> Dosierer, Mischer, Stampfer, Mischbehälter
	on/off gibt "Zutat" in/aus dem Mischbehälter
Waage
	misst den Inhalt des Mischbehälters