# Practice 1

## Aufgabe: 
> Erstellen Sie den Use Case "Cocktail mischen" mit einer textuellen Beschreibung auf einem Blatt Papier. 

## Lösung
- **Name des Anwendungsfalls:** Cocktail mischen
- **Primärer Akteur:** Benutzer
- **Stakeholder und ihre Interessen:** Benutzer hätte gerne einne Cocktail

----

- **Vorbedinung:** System ist gestartet
- **Minimale Nachbedinung:** Das System bietet Cocktais an und erwartet Eingabe
- **Nachbedinung zum Hauptszenario:** Der Cocktail ist entleer und der Mischbehälter gereinigt
- **Auslöser:** Der Benutzer wählt einen Cocktail aus

----

### Hauptszenario
| Schritt | Aktion                                                  |
| ------- | ------------------------------------------------------- |
| 1       | Kommandos werden nach Rezept an Dosierer geschickt      |
| 2       | Ventil von Dosierer X wird geöffnet                     |
| 3       | Wenn Wage Delta erreicht/überschritten, Ventil von Dosierer X schließen |
| 4       | Mixer und/oder Stampfer werden für eine Zeit aktiviert  |

### Erweiterungen
| Schritt | Bedinung                | Aktion                  |
| ------- | ----------------------- | ----------------------- |
| 4a      | Es gibt weitere Zutaten | Schritt 1-3 wiederholen |
