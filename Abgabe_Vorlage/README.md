Bauen und ausführen im JupyterHub: 

1. Ins Terminal navigieren, z. B. in der Konsole mit `cd cpp-sommersemester-2025/Abgabe_Vorlage`
2. Nur beim ersten Mal: Die Befehle `make getSFML` und `make getGTest` ausführen, um Ressourcen herunterzuladen.
3. Das Projekt und die Tests bauen: `make game` bzw. `make tests`
4. Den Pfad im Terminal anpassen: `export LD_LIBRARY_PATH=./SFML/lib:$LD_LIBRARY_PATH`
5. Das Spiel oder die Test ausführen (in der Konsolen-Anwendung, nicht VSCode!): `./game` oder `./tests`