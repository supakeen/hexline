package cmd

import (
	"bufio"
	"os"
	"strings"

	"github.com/spf13/cobra"

	"github.com/supakeen/hexline/internal"
)

var (
	delay int
)

func init() {
	displayCmd.PersistentFlags().IntVarP(&delay, "delay", "d", 500, "delay between lines (in ms)")

	rootCmd.AddCommand(displayCmd)
}

var displayCmd = &cobra.Command{
	Use:        "display [flags] [TEXT...]",
	Short:      "Display text on the display.",
	Long:       "Display text on the display. When [TEXT]s are passed show those, otherwise show lines from STDIN. 500 millisecond delay between each line.",
	Args:       cobra.ArbitraryArgs,
	ArgAliases: []string{"text"},
	Run: func(cmd *cobra.Command, args []string) {
		display, err := internal.NewCharDisplay(devicePath)

		if err != nil {
			panic(err)
		}

		if len(args) > 0 {
			// Arguments were passed, show them.
			display.Display(args, delay, false)
		} else {
			// No arguments, use STDIN and any lines on it.
			s := bufio.NewScanner(os.Stdin)

			for s.Scan() {
				t := strings.TrimSuffix(s.Text(), "\r\n")
				display.Display([]string{t}, delay, false)
			}
		}

	},
}
