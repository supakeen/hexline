package cmd

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"time"

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
		f, err := internal.GetDeviceFile(devicePath)

		if err != nil {
			panic(err)
		}

		defer f.Close()

		if len(args) > 0 {
			// Arguments were passed, show them.
			for _, t := range args {
				f.Write([]byte(fmt.Sprintf("\r%s", t)))
                time.Sleep(time.Duration(delay) * time.Millisecond)
			}
		} else {
			// No arguments, use STDIN and any lines on it.
			s := bufio.NewScanner(os.Stdin)

			for s.Scan() {
				t := strings.TrimSuffix(s.Text(), "\r\n")
				f.Write([]byte(fmt.Sprintf("\r%s", t)))
				time.Sleep(time.Duration(delay) * time.Millisecond)
			}
		}

	},
}
