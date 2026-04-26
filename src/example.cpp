#include <cstdint>
#include <webhook/Webhook.h>

std::int32_t main(int argc, char** argv)
{
	// construct the hook object

	Webhook hook = Webhook("WEBHOOK_URL");

	// setting up basic hook info

	/* you can method chain hook because all the set**** () functions return a reference to the object you created above.
	   ^^ same for EmbedObject*/

	hook.setUsername("RainbowHorse551")
		.setAvatarUrl("IMAGE_URL") // calling this method is not needed but I think a pfp always makes things better
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