library ieee;
use ieee.std_logic_1164.all;
entity decr is
port( a1: in std_logic_vector(3 downto 0);
	sum: out std_logic_vector(3 downto 0);
	cdout: out std_logic);
end decr;
architecture arch1 of decr is
component fa is
port( a,b,cin: in std_logic;
   s,cout: out std_logic);
end component;
signal sig : std_logic_vector(2 downto 0);
begin
x1: fa port map(a1(0), '1', '0', sum(0), sig(0));
x2: fa port map(a1(1), '1', sig(0), sum(1), sig(1)); 
x3: fa port map(a1(2), '1', sig(1), sum(2), sig(2));
x4: fa port map(a1(3), '1', sig(2), sum(3), cdout);
end arch1;
