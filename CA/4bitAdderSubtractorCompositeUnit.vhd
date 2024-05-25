library ieee;
use ieee.std_logic_1164.all;
entity as is
port( a,b:in std_logic_vector(3 downto 0);
	s:out std_logic_vector(3 downto 0);
	sw:in std_logic;
	casout:out std_logic);
end as;

architecture arch1 of as is
component faha is
port( af,bf,cin:in std_logic;
   sf,cout: out std_logic);
end component;
signal sig: std_logic_vector(3 downto 0); 
signal cp: std_logic_vector(2 downto 0); 
begin
sig(0)<= b(0) xor sw;
sig(1)<= b(1) xor sw;
sig(2)<= b(2) xor sw;
sig(3)<= b(3) xor sw;
x1: faha port map(a(0),sig(0),sw,s(0),cp(0));
x2: faha port map(a(1),sig(1),cp(0),s(1),cp(1));
x3: faha port map(a(2),sig(2),cp(1),s(2),cp(2));
x4: faha port map(a(3),sig(3),cp(2),s(3),casout);
end arch1;
