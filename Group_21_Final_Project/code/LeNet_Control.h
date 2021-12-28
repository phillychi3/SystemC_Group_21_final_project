#include "systemc.h"
#include "define.h"
#include "LeNet_Conv.h"
#include "LeNet_Dens.h"
#include "LeNet_Pool.h"
#include <iostream>

using namespace std;

SC_MODULE(Control) {
 sc_in_clk clk;
 sc_in < bool > rst;

 sc_out < DATA_TYPE > data_out;
 sc_in < DATA_TYPE > data_in;

 sc_out < bool > rom_rd;
 sc_out < sc_uint<16> > rom_addr;
 sc_in < DATA_TYPE > rom_data_out;

 sc_out < bool > ram_wr;
 sc_out < sc_uint<16> > ram_addr;
 sc_in < DATA_TYPE > ram_data_out;
 sc_out < DATA_TYPE > ram_data_in;

 sc_out < DATA_TYPE > result;
 sc_out < bool > output_valid;

 // connect to Conv Submodule 0
 sc_in < DATA_TYPE > conv_0_data_out;
 sc_out < DATA_TYPE > conv_0_data_in;
 sc_out < int > conv_0_data_size;

 // connect to Pooling Submodule 0
 sc_in < DATA_TYPE > pool_0_data_out;
 sc_out < DATA_TYPE > pool_0_data_in;
 sc_out < int > pool_0_data_size;

 // connect to Dense Submodule 0
 sc_in < DATA_TYPE > dens_data_out;
 sc_out < DATA_TYPE > dens_data_in;
 sc_out < int > dens_data_size;

 Conv* Conv_0;

 Pool* Pool_0;

 Dens* Dens_0;

 void run();

 SC_CTOR(Control)
 {
  Conv_0 = new Conv("Conv_0");
  Conv_0->clk(clk);

  Pool_0 = new Pool("Pool_0");
  Pool_0->clk(clk);

  Dens_0 = new Dens("Dens_0");
  Dens_0->clk(clk);

  SC_METHOD(run);
  sensitive << clk.pos();
 }
};
