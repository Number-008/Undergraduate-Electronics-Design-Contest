library verilog;
use verilog.vl_types.all;
entity DDS is
    generic(
        ROMAD_WIDTH     : integer := 8
    );
    port(
        CLK             : in     vl_logic;
        RST_N           : in     vl_logic;
        FREQW           : in     vl_logic_vector(31 downto 0);
        PHASEW          : in     vl_logic_vector;
        DA_DB           : out    vl_logic_vector
    );
    attribute mti_svvh_generic_type : integer;
    attribute mti_svvh_generic_type of ROMAD_WIDTH : constant is 1;
end DDS;
