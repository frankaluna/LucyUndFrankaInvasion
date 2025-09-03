Bauen und ausführen im JupyterHub: (haben wir so beibehalten)

1. Ins Terminal navigieren, z. B. in der Konsole mit `cd LucyUndFrankaInvasion`
2. Nur beim ersten Mal: Die Befehle `make getSFML` und `make getGTest` ausführen, um Ressourcen herunterzuladen.
3. Das Projekt und die Tests bauen: `make game` bzw. `make tests`
4. Den Pfad im Terminal anpassen: `export LD_LIBRARY_PATH=./SFML/lib:$LD_LIBRARY_PATH`
5. Das Spiel oder die Test ausführen (in der Konsolen-Anwendung, nicht VSCode!): `./game` oder `./tests`

Ablauf des Spiels:
Nach dem Starten des Spiels befindet sich der Player im ersten Level.
Der Player muss als Alien seine heimischen UFOs verteidigen, indem es auf die attackierenden und nähernden Raumschiffe schießt, welche auch zurückschießen können.
Der Player besitzt drei Leben, welche unten rechts am Bildschirm angezeigt werden, während auf der anderen Seite der Player über seinen aktuellen Score informiert wird.
Der Score ist die Anzahl der erschossenen Raumschiffe, also ein erschossenes Raumschiff ergibt einen Punkt.
Am oberen Bildschirmrand erscheint ab und zu ein UFO, welches der Player zusätzlich abschießen kann und dadurch ein neues Leben erhält.

Wenn alle Invader Raumschiffe erschossen wurden, begibt sich der Player in das nächste Level, wo die Geschwindigkeit der Raumschiffe und der Laser zunimmt.

Wenn die heimischen UFOs 33 mal getroffen wurden, sind diese für immer zerstört.
Wenn der Player sich unter den heimischen UFOs befindet kann er nicht getroffen werden, allerdings auch selber keine Invader erschießen.

Das Spiel endet, wenn alle drei Leben des Players erloschen sind oder die angreifenden Raumschiffe, die heimischen UFOs erreicht haben, dies wird durch "GAME OVER" auf dem Bildschirm bekannt gegeben.

Steuerung:
Mit der linken Pfeiltaste bewegt der Player sich nach links.
Mit der rechten nach rechts.
Schießen kann die Laser mit der Leertaste.
Beim loslassen der Tasten stoppt die Bewegung.

Quellen und Referenzquellen für unsere Spritesheets (welche von uns selber per Pixelapp kopiert und angepasst wurden):
Hintergrundbild: 
https://1.bp.blogspot.com/-plHRzEJSUl4/Uid-2e2wx3I/AAAAAAAAOqY/FhpeeDJ3U4k/s1600/Sprite_background_effects_0088.png 
Alien und spaceships
https://static.vecteezy.com/system/resources/previews/023/976/261/original/retro-space-arcade-game-invaders-spaceship-pixel-invader-monster-and-retro-video-games-pixel-art-isolated-objects-illustration-set-vector.jpg 
Shields:
https://t4.ftcdn.net/jpg/05/13/95/49/360_F_513954974_drot85xxFqoj30s0FAZUCHtRC70qXGKl.jpg

