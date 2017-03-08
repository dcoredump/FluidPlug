#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fluidsynth.h>

int main(int argc, char **argv)
{
	fluid_settings_t* settings = new_fluid_settings();
	fluid_synth_t* synth = new_fluid_synth(settings);
	int synthId;
	fluid_sfont_t* sfont;
	size_t count;
	fluid_preset_t preset;

	if(argc!=2 || strlen(argv[1])==0)
	{
		/* Usage */
		printf("%s <soundfont>\n",argv[0]);
		exit(1);
	}

	if(!(synthId=fluid_synth_sfload(synth,argv[1],0)))
	{
		printf("Cannot load soundfont \'%s\'\n",argv[1]);
		exit(10);
	}
	if(!(sfont=fluid_synth_get_sfont_by_id(synth,synthId)))
	{
		printf("Cannot map soundfont \'%s\'\n",argv[1]);
		exit(11);
	}

	/* Reset the iteration */
	sfont->iteration_start(sfont);

	/* Loop over presets */
	for (count = 0; sfont->iteration_next(sfont, &preset) != 0;)
	{
        	++count;

		// Get preset name
		char* presetname = preset.get_name(&preset);
		int banknum = preset.get_banknum(&preset);
		int num = preset.get_num(&preset);

		printf("%d:%d %s\n",banknum,num,presetname);
	}
}
