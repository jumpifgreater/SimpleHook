#include <cstdint>
#include <webhook/Webhook.h>

std::int32_t main(int argc, char** argv)
{
	// construct the hook object

	Webhook hook = Webhook("https://canary.discord.com/api/webhooks/1497934934952771735/SzJ92EsEhFsz8_G2CZ34bHG7QwH76V2EgHEejx_3bjCw3LcXT-o43SO6rns-GNl9MowM");

	// setting up basic hook info

	/* you can method chain hook because all the set**** () functions return a reference to the object you created above.
	   ^^ same for EmbedObject*/

	hook.setUsername("RainbowHorse551")
		.setAvatarUrl("https://cdn.discordapp.com/attachments/1442481780757237854/1457727194418905108/image.png?ex=69eebb7e&is=69ed69fe&hm=027eab2d3097e386d4312be1feda5c6684acf60f546f0af2feab180586021ef6&") // calling this method is not needed but I think a pfp always makes things better
		.setContent("@everyone hook test123"); // this is the content of the message. I will cover the embeds later.

	// again having an embed is optional but i like them and you can customise them with alot of things
	
	EmbedObject embed = EmbedObject()
		.setTitle("Example Embed")
		.setDescription("example description") // optional.
		.addField("field", "content of the field", true) // addfield(name, value, b_inline); | optional aswell.
		.setColour(Colour::MAGENTA); // again, optional. ps: if you don't call this method it will be black by default.

	// add the embed to the hook content
	hook.addEmbed(embed);

	// lastly execute the hook
	hook.execute();
}