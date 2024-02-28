library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity PC is
    port (
        clk  : in std_logic;
        reset: in std_logic;
        start: in std_logic;
        inf  : in std_logic;
        egal : in std_logic;
        getA : out std_logic;
        getB : out std_logic;
        subBA: out std_logic;
        ldA  : out std_logic;
        ldB  : out std_logic;
        done : out std_logic
    );
end PC;

architecture mixte of PC is
  -- Définir ici le nécessaire pour la réalisation de l'automate.
  -- Attention à ne pas utiliser pour les noms des états des mots clés du langage comme
  -- wait, end, init... Par exemple nommer l'état "wait" sWait (comme "state Wait")

begin
-- A completer
-- Ici pour la partie bascules D
-- Ici pour la description des transition (état futur en fonction de l'état courant et des entrées)
-- et pour déterminer les sorties pour chaque état
end mixte;
