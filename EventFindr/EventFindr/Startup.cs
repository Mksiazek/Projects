using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(EventFindr.Startup))]
namespace EventFindr
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
