library ieee;
use ieee.std_logic_1164.all;
entity incr is
port( a1: in std_logic_vector(3 downto 0);
	sum: out std_logic_vector(3 downto 0);
	cout: out std_logic);
end incr;
architecture arch1 of incr is
component ha is
port( a,b:in std_logic;
   s,c: out std_logic);
end component;
signal sig : std_logic_vector(2 downto 0);
begin
x1: ha port map(a1(0), '1', sum(0), sig(0));
x2: ha port map(a1(1), sig(0), sum(1), sig(1)); 
x3: ha port map(a1(2), sig(1), sum(2), sig(2));
x4: ha port map(a1(3), sig(2), sum(3), cout);
end arch1;
